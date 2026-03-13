import argparse
import os
from typing import Dict, List

import matplotlib.pyplot as plt
import rosbag2_py
from rclpy.serialization import deserialize_message
from rosidl_runtime_py.utilities import get_message
from sensor_msgs.msg import JointState


def _detect_storage_id_from_metadata(bag_path: str) -> str:
	metadata_path = os.path.join(bag_path, 'metadata.yaml')
	if not os.path.isfile(metadata_path):
		return ''

	try:
		with open(metadata_path, 'r', encoding='utf-8') as metadata_file:
			for raw_line in metadata_file:
				line = raw_line.strip()
				if line.startswith('storage_identifier:'):
					return line.split(':', 1)[1].strip()
	except OSError:
		return ''

	return ''


def _open_reader_with_storage(
	reader: rosbag2_py.SequentialReader,
	bag_path: str,
	requested_storage_id: str,
):
	converter_options = rosbag2_py.ConverterOptions('', '')
	detected_storage_id = _detect_storage_id_from_metadata(bag_path)

	storage_candidates = []
	if requested_storage_id and requested_storage_id != 'auto':
		storage_candidates.append(requested_storage_id)
	else:
		if detected_storage_id:
			storage_candidates.append(detected_storage_id)
		storage_candidates.extend(['sqlite3', 'mcap'])

	unique_candidates = []
	for storage_id in storage_candidates:
		if storage_id and storage_id not in unique_candidates:
			unique_candidates.append(storage_id)

	last_error = None
	for storage_id in unique_candidates:
		try:
			storage_options = rosbag2_py.StorageOptions(uri=bag_path, storage_id=storage_id)
			reader.open(storage_options, converter_options)
			print(f'[INFO] Rosbag opened with storage_id={storage_id}')
			return
		except RuntimeError as error:
			last_error = error

	raise RuntimeError(
		f'Could not open rosbag at {bag_path}. '
		f'Tried storages: {unique_candidates}. '
		f'Last error: {last_error}'
	)


def _stamp_to_seconds(msg, fallback_ns: int) -> float:
	sec = float(getattr(msg.header.stamp, 'sec', 0.0))
	nanosec = float(getattr(msg.header.stamp, 'nanosec', 0.0))
	stamp = sec + nanosec * 1e-9
	if stamp <= 0.0:
		return fallback_ns * 1e-9
	return stamp


def _to_relative_time(time_vector: List[float]) -> List[float]:
	if not time_vector:
		return []
	t0 = time_vector[0]
	return [t - t0 for t in time_vector]


def read_rosbag_for_joints(
	bag_path: str,
	joint_states_topic: str,
	kalman_joint_states_topic: str,
	desired_joint_states_topic: str,
	storage_id: str,
):
	joint_data = {'t': [], 'joint1_pos': [], 'joint2_pos': []}
	kalman_data = {'t': [], 'joint1_pos': [], 'joint2_pos': []}
	desired_data = {'t': [], 'joint1_pos': [], 'joint2_pos': []}

	selected_topics = {joint_states_topic, kalman_joint_states_topic, desired_joint_states_topic}

	reader = rosbag2_py.SequentialReader()
	_open_reader_with_storage(reader, bag_path, storage_id)

	topic_type_map = {
		topic.name: topic.type
		for topic in reader.get_all_topics_and_types()
	}

	msg_cls_map = {}
	for topic in selected_topics:
		msg_type = topic_type_map.get(topic)
		if msg_type is not None:
			msg_cls_map[topic] = get_message(msg_type)

	while reader.has_next():
		topic, serialized_data, bag_time_ns = reader.read_next()
		if topic not in msg_cls_map:
			continue

		msg = deserialize_message(serialized_data, msg_cls_map[topic])
		timestamp = _stamp_to_seconds(msg, bag_time_ns)

		if isinstance(msg, JointState):
			if 'joint1' not in msg.name or 'joint2' not in msg.name:
				continue
			idx1 = msg.name.index('joint1')
			idx2 = msg.name.index('joint2')

			if len(msg.position) > max(idx1, idx2):
				if topic == joint_states_topic:
					joint_data['t'].append(timestamp)
					joint_data['joint1_pos'].append(msg.position[idx1])
					joint_data['joint2_pos'].append(msg.position[idx2])
				elif topic == kalman_joint_states_topic:
					kalman_data['t'].append(timestamp)
					kalman_data['joint1_pos'].append(msg.position[idx1])
					kalman_data['joint2_pos'].append(msg.position[idx2])
				elif topic == desired_joint_states_topic:
					desired_data['t'].append(timestamp)
					desired_data['joint1_pos'].append(msg.position[idx1])
					desired_data['joint2_pos'].append(msg.position[idx2])

	return joint_data, kalman_data, desired_data


def plot_joint_comparison(
	joint_data: Dict[str, List[float]],
	kalman_data: Dict[str, List[float]],
	desired_data: Dict[str, List[float]]
):
	joint_t = _to_relative_time(joint_data['t'])
	kalman_t = _to_relative_time(kalman_data['t'])
	desired_t = _to_relative_time(desired_data['t'])

	fig, axes = plt.subplots(2, 1, figsize=(12, 10), sharex=True)
	fig.suptitle('Joint States vs Kalman vs Desired Position')

	# Joint 1
	if desired_t: axes[0].plot(desired_t, desired_data['joint1_pos'], label='Desired joint1', linestyle='--', linewidth=2)
	if joint_t: axes[0].plot(joint_t, joint_data['joint1_pos'], label='True joint1', alpha=0.8)
	if kalman_t: axes[0].plot(kalman_t, kalman_data['joint1_pos'], label='Kalman joint1', alpha=0.8)
	axes[0].set_ylabel('Position (rad)')
	axes[0].set_title('Joint 1 Comparison')
	axes[0].grid(True)
	axes[0].legend()

	# Joint 2
	if desired_t: axes[1].plot(desired_t, desired_data['joint2_pos'], label='Desired joint2', linestyle='--', linewidth=2)
	if joint_t: axes[1].plot(joint_t, joint_data['joint2_pos'], label='True joint2', alpha=0.8)
	if kalman_t: axes[1].plot(kalman_t, kalman_data['joint2_pos'], label='Kalman joint2', alpha=0.8)
	axes[1].set_ylabel('Position (rad)')
	axes[1].set_xlabel('Time (s)')
	axes[1].set_title('Joint 2 Comparison')
	axes[1].grid(True)
	axes[1].legend()

	fig.tight_layout()
	return fig


def main():
	parser = argparse.ArgumentParser(
		description='Plot true joint states vs kalman filter vs desired position from a rosbag2.'
	)
	parser.add_argument('bag_path', help='Path to the rosbag2 directory (e.g., ./my_bag)')
	parser.add_argument('--joint-states-topic', default='/joint_states')
	parser.add_argument('--kalman-topic', default='/kalman_joint_states')
	parser.add_argument('--desired-topic', default='/desired_joint_states')
	parser.add_argument(
		'--storage-id',
		default='auto',
		help='Rosbag storage: auto | sqlite3 | mcap (default: auto)',
	)
	parser.add_argument('--save-dir', default='', help='Directory to save PNGs (optional)')
	parser.add_argument('--no-show', action='store_true', help='Do not display matplotlib window')
	args = parser.parse_args()

	joint_data, kalman_data, desired_data = read_rosbag_for_joints(
		bag_path=args.bag_path,
		joint_states_topic=args.joint_states_topic,
		kalman_joint_states_topic=args.kalman_topic,
		desired_joint_states_topic=args.desired_topic,
		storage_id=args.storage_id,
	)

	fig_joints = plot_joint_comparison(joint_data, kalman_data, desired_data)

	if args.save_dir:
		os.makedirs(args.save_dir, exist_ok=True)
		if fig_joints is not None:
			fig_joints.savefig(os.path.join(args.save_dir, 'joint_comparison.png'), dpi=160)
		print(f'[OK] Figures saved in: {args.save_dir}')

	if not args.no_show:
		plt.show()


if __name__ == '__main__':
	main()
