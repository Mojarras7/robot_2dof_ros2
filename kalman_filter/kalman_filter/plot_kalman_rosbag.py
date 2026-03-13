import argparse
import os
from typing import Dict, List

import matplotlib.pyplot as plt
import rosbag2_py
from rclpy.serialization import deserialize_message
from rosidl_runtime_py.utilities import get_message
from sensor_msgs.msg import Imu, JointState


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
			print(f'[INFO] Rosbag abierto con storage_id={storage_id}')
			return
		except RuntimeError as error:
			last_error = error

	raise RuntimeError(
		f'No se pudo abrir el rosbag en {bag_path}. '
		f'Storages probados: {unique_candidates}. '
		f'Último error: {last_error}'
	)


def _stamp_to_seconds(msg, fallback_ns: int) -> float:
	sec = float(getattr(msg.header.stamp, 'sec', 0.0))
	nanosec = float(getattr(msg.header.stamp, 'nanosec', 0.0))
	stamp = sec + nanosec * 1e-9
	if stamp <= 0.0:
		return fallback_ns * 1e-9
	return stamp


def _create_imu_series() -> Dict[str, List[float]]:
	return {
		't': [],
		'ang_x': [],
		'ang_y': [],
		'ang_z': [],
		'lin_x': [],
		'lin_y': [],
		'lin_z': [],
	}


def _append_imu(series: Dict[str, List[float]], t: float, msg: Imu):
	series['t'].append(t)
	series['ang_x'].append(msg.angular_velocity.x)
	series['ang_y'].append(msg.angular_velocity.y)
	series['ang_z'].append(msg.angular_velocity.z)
	series['lin_x'].append(msg.linear_acceleration.x)
	series['lin_y'].append(msg.linear_acceleration.y)
	series['lin_z'].append(msg.linear_acceleration.z)


def read_rosbag(
	bag_path: str,
	link1_noisy_topic: str,
	link1_filtered_topic: str,
	link2_noisy_topic: str,
	link2_filtered_topic: str,
	joint_states_topic: str,
	storage_id: str,
):
	imu_data = {
		link1_noisy_topic: _create_imu_series(),
		link1_filtered_topic: _create_imu_series(),
		link2_noisy_topic: _create_imu_series(),
		link2_filtered_topic: _create_imu_series(),
	}

	joint_data = {
		't': [],
		'joint1_pos': [],
		'joint2_pos': [],
		'joint1_vel': [],
		'joint2_vel': [],
		'link2_ref_vel': [],
	}

	selected_topics = set(imu_data.keys()) | {joint_states_topic}

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

	if joint_states_topic not in msg_cls_map:
		print(f'[WARN] Topic {joint_states_topic} no existe en el rosbag.')

	for imu_topic in imu_data.keys():
		if imu_topic not in msg_cls_map:
			print(f'[WARN] Topic {imu_topic} no existe en el rosbag.')

	while reader.has_next():
		topic, serialized_data, bag_time_ns = reader.read_next()
		if topic not in msg_cls_map:
			continue

		msg = deserialize_message(serialized_data, msg_cls_map[topic])
		timestamp = _stamp_to_seconds(msg, bag_time_ns)

		if topic in imu_data and isinstance(msg, Imu):
			_append_imu(imu_data[topic], timestamp, msg)
		elif topic == joint_states_topic and isinstance(msg, JointState):
			name_to_index = {name: idx for idx, name in enumerate(msg.name)}
			if 'joint1' not in name_to_index or 'joint2' not in name_to_index:
				continue

			idx1 = name_to_index['joint1']
			idx2 = name_to_index['joint2']

			if idx1 >= len(msg.position) or idx2 >= len(msg.position):
				continue
			if idx1 >= len(msg.velocity) or idx2 >= len(msg.velocity):
				continue

			joint1_pos = msg.position[idx1]
			joint2_pos = msg.position[idx2]
			joint1_vel = msg.velocity[idx1]
			joint2_vel = msg.velocity[idx2]

			joint_data['t'].append(timestamp)
			joint_data['joint1_pos'].append(joint1_pos)
			joint_data['joint2_pos'].append(joint2_pos)
			joint_data['joint1_vel'].append(joint1_vel)
			joint_data['joint2_vel'].append(joint2_vel)
			joint_data['link2_ref_vel'].append(joint1_vel + joint2_vel)

	return imu_data, joint_data


def _to_relative_time(time_vector: List[float]) -> List[float]:
	if not time_vector:
		return []
	t0 = time_vector[0]
	return [t - t0 for t in time_vector]


def plot_link_comparison(
	link_name: str,
	noisy: Dict[str, List[float]],
	filtered: Dict[str, List[float]],
	joint_data: Dict[str, List[float]],
	joint_reference_key: str,
):
	noisy_t = _to_relative_time(noisy['t'])
	filtered_t = _to_relative_time(filtered['t'])
	joint_t = _to_relative_time(joint_data['t'])

	fig, axes = plt.subplots(4, 1, figsize=(12, 12), sharex=False)
	fig.suptitle(f'Comparación IMU ruidosa vs filtrada - {link_name}')

	axes[0].plot(noisy_t, noisy['ang_z'], label='IMU ruidosa ωz', alpha=0.7)
	axes[0].plot(filtered_t, filtered['ang_z'], label='IMU filtrada ωz', linewidth=2)
	if joint_t:
		axes[0].plot(joint_t, joint_data[joint_reference_key], label='Joint states referencia', linestyle='--')
	axes[0].set_ylabel('rad/s')
	axes[0].set_title('Velocidad angular Z')
	axes[0].grid(True)
	axes[0].legend()

	axes[1].plot(noisy_t, noisy['lin_x'], label='IMU ruidosa ax', alpha=0.7)
	axes[1].plot(filtered_t, filtered['lin_x'], label='IMU filtrada ax', linewidth=2)
	axes[1].set_ylabel('m/s²')
	axes[1].set_title('Aceleración lineal X')
	axes[1].grid(True)
	axes[1].legend()

	axes[2].plot(noisy_t, noisy['lin_y'], label='IMU ruidosa ay', alpha=0.7)
	axes[2].plot(filtered_t, filtered['lin_y'], label='IMU filtrada ay', linewidth=2)
	axes[2].set_ylabel('m/s²')
	axes[2].set_title('Aceleración lineal Y')
	axes[2].grid(True)
	axes[2].legend()

	axes[3].plot(noisy_t, noisy['lin_z'], label='IMU ruidosa az', alpha=0.7)
	axes[3].plot(filtered_t, filtered['lin_z'], label='IMU filtrada az', linewidth=2)
	axes[3].set_ylabel('m/s²')
	axes[3].set_xlabel('Tiempo [s]')
	axes[3].set_title('Aceleración lineal Z')
	axes[3].grid(True)
	axes[3].legend()

	fig.tight_layout()
	return fig


def plot_joint_states(joint_data: Dict[str, List[float]]):
	joint_t = _to_relative_time(joint_data['t'])
	if not joint_t:
		return None

	fig, axes = plt.subplots(2, 1, figsize=(12, 8), sharex=True)
	fig.suptitle('Joint states')

	axes[0].plot(joint_t, joint_data['joint1_pos'], label='joint1 posición')
	axes[0].plot(joint_t, joint_data['joint2_pos'], label='joint2 posición')
	axes[0].set_ylabel('rad')
	axes[0].set_title('Posición articular')
	axes[0].grid(True)
	axes[0].legend()

	axes[1].plot(joint_t, joint_data['joint1_vel'], label='joint1 velocidad')
	axes[1].plot(joint_t, joint_data['joint2_vel'], label='joint2 velocidad')
	axes[1].plot(joint_t, joint_data['link2_ref_vel'], label='ref ω link2 (j1+j2)', linestyle='--')
	axes[1].set_ylabel('rad/s')
	axes[1].set_xlabel('Tiempo [s]')
	axes[1].set_title('Velocidad articular')
	axes[1].grid(True)
	axes[1].legend()

	fig.tight_layout()
	return fig


def main():
	parser = argparse.ArgumentParser(
		description='Grafica IMU ruidosa vs filtrada (link1/link2) y joint_states desde un rosbag2.'
	)
	parser.add_argument('bag_path', help='Ruta al directorio del rosbag2 (por ejemplo, ./my_bag)')
	parser.add_argument('--link1-noisy-topic', default='/link1/ruido_imu')
	parser.add_argument('--link1-filtered-topic', default='/link1/imu_filtrada')
	parser.add_argument('--link2-noisy-topic', default='/link2/ruido_imu')
	parser.add_argument('--link2-filtered-topic', default='/link2/imu_filtrada')
	parser.add_argument('--joint-states-topic', default='/joint_states')
	parser.add_argument(
		'--storage-id',
		default='auto',
		help='Storage del rosbag: auto | sqlite3 | mcap (default: auto)',
	)
	parser.add_argument('--save-dir', default='', help='Directorio para guardar PNGs (opcional)')
	parser.add_argument('--no-show', action='store_true', help='No abrir ventana de matplotlib')
	args = parser.parse_args()

	imu_data, joint_data = read_rosbag(
		bag_path=args.bag_path,
		link1_noisy_topic=args.link1_noisy_topic,
		link1_filtered_topic=args.link1_filtered_topic,
		link2_noisy_topic=args.link2_noisy_topic,
		link2_filtered_topic=args.link2_filtered_topic,
		joint_states_topic=args.joint_states_topic,
		storage_id=args.storage_id,
	)

	fig_link1 = plot_link_comparison(
		'link1',
		imu_data[args.link1_noisy_topic],
		imu_data[args.link1_filtered_topic],
		joint_data,
		'joint1_vel',
	)
	fig_link2 = plot_link_comparison(
		'link2',
		imu_data[args.link2_noisy_topic],
		imu_data[args.link2_filtered_topic],
		joint_data,
		'link2_ref_vel',
	)
	fig_joints = plot_joint_states(joint_data)

	if args.save_dir:
		os.makedirs(args.save_dir, exist_ok=True)
		fig_link1.savefig(os.path.join(args.save_dir, 'comparacion_link1.png'), dpi=160)
		fig_link2.savefig(os.path.join(args.save_dir, 'comparacion_link2.png'), dpi=160)
		if fig_joints is not None:
			fig_joints.savefig(os.path.join(args.save_dir, 'joint_states.png'), dpi=160)
		print(f'[OK] Figuras guardadas en: {args.save_dir}')

	if not args.no_show:
		plt.show()


if __name__ == '__main__':
	main()
