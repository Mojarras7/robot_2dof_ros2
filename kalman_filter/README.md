# kalman_filter (ROS 2 Python)

ROS 2 package to filter noisy IMU data from a 2-DOF robotic arm using a Kalman Filter to accurately estimate joint angles by fusing the gyroscope and accelerometer.

This converts the independent raw sensor data (`/link1/ruido_imu` and `/link2/ruido_imu`) into clean, estimated joint positions output to `/kalman_joint_states`. 

## 1) Build

```bash
cd ~/Documents/robot_2dof_ros2
colcon build --packages-select kalman_filter
source install/setup.bash
```

## 2) Run the Kalman filter node

Start the simulation first, then run the kalman filter:

```bash
source install/setup.bash
ros2 run kalman_filter kalman_filter_node
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
