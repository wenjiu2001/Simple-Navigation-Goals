# Simple-Navigation-Goals

"simple_nav_goals" constitutes a ROS package for straightforward task navigation.

## Environment

- Ubuntu 20.04
- ROS Noetic

## Requirements

- Gazebo
   ```
   sudo apt-get install gazebo11 && sudo apt-get install libgazebo11-dev
   ```
- Turtlebot3
   ```
   sudo apt-get install ros-noetic-turtlebot3*
   ```
- DWA Local Planner
   ```
   sudo apt-get install ros-noetic-dwa-local-planner*
   ```

## Install and Build

1. Navigating to the "src" directory within your catkin workspace :
   ```
   cd ~/catkin_ws/src
   ```
2. Clone simple_nav_goals package for github :
   ```
   git clone https://github.com/wenjiu2001/Simple-Navigation-Goals.git simple_nav_goals
   ```
3. Build simple_nav_goals package :
   ```
   cd ~/catkin_ws && catkin_make
   ```
4. Package environment setup :
   ```
   source ./devel/setup.sh
   ```

## How to Use
1. Choosing a robotic model :

   Note: "{TURTLEBOT3_MODEL}" represents the name of the utilized models: "burger", "waffle", or "waffle_pi".
   ```
   export TURTLEBOT3_MODEL={TURTLEBOT3_MODEL}
   ```
   Add permanent workspace environment variables.
   ```
   echo "export TURTLEBOT3_MODEL={TURTLEBOT3_MODEL}" >> ~/.bashrc
   ```
   ```
   source ~/.bashrc
   ```
2. Launch Simulation World :
   ```
   roslaunch turtlebot3_gazebo turtlebot3_world.launch
   ```
3. Launch Navigation Goals :
   ```
   roslaunch simple_nav_goals simple_nav_goals.launch
   ```
   
## References

- Ubuntu install of ROS Noetic (https://wiki.ros.org/noetic/Installation/Ubuntu)
- Install Gazebo using Ubuntu packages (https://classic.gazebosim.org/tutorials?tut=install_ubuntu)
- TurtleBot3 Simulation (https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/)
- SendingSimpleGoals (https://wiki.ros.org/navigation/Tutorials/SendingSimpleGoals)
