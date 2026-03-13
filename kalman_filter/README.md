# kalman_filter (ROS 2 Python)

ROS 2 package to filter noisy IMU data from a 2-DOF robotic arm using a Kalman Filter to accurately estimate joint angles by fusing the gyroscope and accelerometer.

This converts the independent raw sensor data (`/link1/ruido_imu` and `/link2/ruido_imu`) into clean, estimated joint positions output to `/kalman_joint_states`. 

## 1) Build

```bash
cd ~/Documents/robot_2dof_ros2
colcon build --packages-select kalman_filter
source install/setup.bash
```

## 2) Run the Kalman filter system

Start the simulation first, then run the kalman filter launch file. This launch file will start both the `kalman_filter_node` (which estimates the joint states) and the `kalman_comparison_node` (which logs real-time error differences in the terminal):

```bash
source install/setup.bash
ros2 launch kalman_filter kalman_filter.launch.py
```

## 3) View the Live Results (Compare with Ground Truth)

Because the node publishes standard `JointState` messages, you can easily use `rqt_plot` to compare the true simulated angles with our Kalman filtered estimations in real-time.

Open a new terminal and run:

**For Joint 1 (Link 1):**
```bash
ros2 run rqt_plot rqt_plot /joint_states/position[0] /kalman_joint_states/position[0]
```

**For Joint 2 (Link 2):**
```bash
ros2 run rqt_plot rqt_plot /joint_states/position[1] /kalman_joint_states/position[1]
```

*(Note: Ensure you are publishing commands to the robot so it moves! The plots will overlay the ground truth from Gazebo and your new filtered estimation. Due to the 2-DOF setup, the node automatically computes the Joint 2 angle as `Link2_Abs_Angle - Link1_Abs_Angle`.)*

## 4) Plot Offline Data (Rosbag)

If you record a rosbag, you can use the `plot_comparison.py` script to graph the true `joint_states`, the Kalman estimated `kalman_joint_states`, and the `desired_joint_states` (published by the control node).

### Record the bag:
While the robot is running, run:
```bash
ros2 bag record /joint_states /kalman_joint_states /desired_joint_states
```
Send target positions via:
```bash
ros2 topic pub --once /target_coordinate geometry_msgs/msg/Point "{x: 1.0, y: 1.0}"
```
Let the robot settle, then end the rosbag with `Ctrl+C`.

### Plot the data:
Run the script passing the path to the recorded rosbag folder:
```bash
python3 kalman_filter/kalman_filter/plot_comparison.py rosbag2_2026_...
```
*(Replace `path/to/your/rosbag_directory` with the actual folder created, e.g., `rosbag2_2026_...`)*

This script uses `matplotlib` to plot side-by-side comparisons of the desired trajectories, actual ground-truth trajectories, and the Kalman filter estimations.

## 5) Results

Here are the results of comparing our Kalman Filter estimations vs True States vs Desired Positions:

### Joint 1 Comparison
![Comparison Link 1](images/comparacion_1.png)

### Joint 2 Comparison
![Comparison Link 2](images/comparacion_2.png)
