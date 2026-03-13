
# kalman_filter (ROS 2 Python)

ROS 2 package to filter noisy IMU data for two links using a Kalman filter, then compare:

- `/link1/ruido_imu` vs `/link1/imu_filtrada`
- `/link2/ruido_imu` vs `/link2/imu_filtrada`
- `/joint_states` as reference

## 1) Build

```bash
cd $WORKSPACE
colcon build --packages-select kalman_filter
source /install/setup.bash
```

## 2) Run the Kalman filter node (launch file)

```bash
source /install/setup.bash
ros2 launch kalman_filter dual_imu_kalman.launch.py
```

Default launch parameters:

- `input_topic_link1:=/link1/ruido_imu`
- `output_topic_link1:=/link1/imu_filtrada`
- `input_topic_link2:=/link2/ruido_imu`
- `output_topic_link2:=/link2/imu_filtrada`
- `process_noise:=0.01`
- `measurement_noise:=0.05`

## 3) Record a rosbag

Open another terminal:

```bash
source /install/setup.bash
mkdir -p /bags
ros2 bag record \
  -o /bags/kalman_dual_imu \
  /joint_states \
  /link1/ruido_imu \
  /link2/ruido_imu \
  /link1/imu_filtrada \
  /link2/imu_filtrada
```

## 4) Generate plots from rosbag

Interactive plots:

```bash

source /install/setup.bash
ros2 run kalman_filter plot_kalman_rosbag /bags/kalman_dual_imu
```

Save PNG files without opening a GUI window:

```bash
source /install/setup.bash
ros2 run kalman_filter plot_kalman_rosbag \
  /bags/kalman_dual_imu \
  --save-dir /bags/kalman_dual_imu/plots \
  --no-show
```

Expected output files:

- `comparacion_link1.png`
- `comparacion_link2.png`
- `joint_states.png`

## Notes

- The plotting script auto-detects rosbag storage (`sqlite3` or `mcap`) from `metadata.yaml`.
- If needed, force a storage plugin manually:

```bash
ros2 run kalman_filter plot_kalman_rosbag /bags/kalman_dual_imu --storage-id mcap
```
