# robot_2dof_ros2

This workspace contains a 2-DOF robot simulation with Gazebo + ros2_control.

## What changed for kinematics & debugging

- **D-H Convention Alignment**: `joint1` and `joint2` now rotate around their local `Z-axis` (0 0 1). The base link passes this rotation on properly so the robot operates entirely in the XY plane.
- **Planar Gravity World**: We introduced a custom Gazebo world (`planar_gravity.sdf`) where gravity points in the `-Y` direction. This lets the robot rest naturally "downward" in the 2D plane, matching textbook Inverse Kinematics math.
- **Controller modes**: You can now switch between a `position_controller` (for direct angle commands) and an `effort_controller` (for torque/PID control).
- **Inverse Kinematics integration**: `control.launch.py` now supports routing IK outputs directly to position commands without needing PID effort calculations.

---

## Build Space

From the workspace root, make sure you build after making any changes (especially to `.py` files, `.urdf`, or `.sdf` files):

```bash
colcon build
source install/setup.bash
```

---

## 1) Launching the Simulation

You can launch Gazebo and spawn the robot in either `position` or `effort` mode.
Using position mode guarantees the robot perfectly matches the angles given by IK (best for debugging kinematics).

```bash
# Terminal 1: Launch simulation in Position Control Mode (Recommended right now)
ros2 launch simulation_2dof simulation_2dof.launch.py controller_mode:=position

# Or to test your PID loops later:
# ros2 launch simulation_2dof simulation_2dof.launch.py controller_mode:=effort
```

---

## 2) Running Inverse Kinematics & Commands

Once Gazebo is open and the controllers are spawned, you need to start the control pipeline. Our updated system now lets you keep the nodes running and send multiple coordinates to watch the arm dynamically alternate between "Elbow Up" and "Elbow Down" configurations.

### Choosing your Control Strategy

The control node requires a `mode` parameter (`position` or `effort`), which **MUST** match the physics simulation launch mode you chose in Step 1. 

If running in `effort` mode, we now support a custom `control_type`. By default, the system uses a **Computed Torque (Feedback Linearization)** algorithm derived from the robot's real mass matrices. You can also switch this to standard `pid` to compare performance.

```bash
# Terminal 2: Source workspace and launch control
source install/setup.bash

# Option 1: Ideal Position Control (Bypasses physics forces)
ros2 launch control control.launch.py mode:=position

# Option 2: Advanced Computed Torque (Feedback Linearization - Recommended for Effort)
ros2 launch control control.launch.py mode:=effort control_type:=computed_torque

# Option 3: Basic PID Controller (For comparison)
ros2 launch control control.launch.py mode:=effort control_type:=pid
```

### Sending Coordinates Dynamically 

With the `control.launch.py` running in Terminal 2, you can now send (X, Y) target coordinates on the fly using a standard ROS 2 topic.

```bash
# Terminal 3: Source workspace, then publish a Point
source install/setup.bash

# Tell the robot to reach a specific (x, y) coordinate. 
# Run this exact command multiple times to watch the arm flip between elbow-up and elbow-down!
ros2 topic pub --once /target_coordinate geometry_msgs/msg/Point "{x: 1.0, y: 1.0}"
```

### Manual Joint Commands (Debugging without IK)

If you strictly want to send bare angles (in radians) bypassing the IK logic:

```bash
ros2 topic pub /position_controller/commands std_msgs/msg/Float64MultiArray "{data: [0.5, -0.3]}" --once
```

---

## Useful quick checks

List active controllers:

```bash
ros2 control list_controllers
```

Check what coordinates the robot actually sees itself at:

```bash
ros2 topic echo /joint_states
```

---

## 3) Kalman Filter Sensor Fusion

We implemented a Kalman Filter that fuses the gyro and accelerometer data from the IMUs on both links to estimate the true joint angles in real time. 

Start the simulation first (Step 1), then run the Kalman filter node:

```bash
# In a new terminal: Source workspace and run Kalman Filter
source install/setup.bash
ros2 run kalman_filter kalman_filter_node
```

To easily compare the true simulated angles with our Kalman filtered estimations without relying on external plotting tools, run the custom comparison node in a new terminal:

```bash
source install/setup.bash
ros2 run kalman_filter kalman_comparison_node
```

This will print a clean, side-by-side terminal output every second confirming the raw `joint_states` against the filtered `kalman_joint_states` estimations and their absolute difference.

*(Note: As an alternative if you have a working GUI, you can visualize the topics side-by-side by running `ros2 run rqt_plot rqt_plot` and manually adding `/joint_states/position[0]` and `/kalman_joint_states/position[0]` to the plot)*
