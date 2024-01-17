# Simple-Navigation-Goals

[![License: CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC_BY--NC--SA_4.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc-sa/4.0/)
[![Ubuntu:Focal](https://img.shields.io/badge/Ubuntu-Focal-brightgreen)](https://releases.ubuntu.com/focal/)
[![ROS:Noetic](https://img.shields.io/badge/ROS-Noetic-blue)](https://wiki.ros.org/noetic/Installation/Ubuntu)

<kbd> <br> English <br> </kbd>
<kbd> <br> [简体中文][zh-CN] <br> </kbd>
<kbd> <br> [繁體中文][zh-TW] <br> </kbd>

[zh-CN]: README_zh-CN.md
[zh-TW]: README_zh-TW.md

"simple_nav_goals" constitutes a ROS package for straightforward task navigation.

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

Adjustments can be made by modifying the following parameters:

| Parameter name    | Data Type | Detail                                                                                                    |
| ----------------- | --------- | --------------------------------------------------------------------------------------------------------- |
| model             | string    | Set the Turtlebot3 robot model. <br/>default: `null`                                                      |
| map_file          |           | Set the map and parameters for robot navigation. <br/>default: `$(find simple_nav_goals)/map/map.yaml`    |
| open_rviz         | bool      | Set whether to initiate RViz. <br/>default: `true`                                                        |
| move_forward_only | bool      | Set the robot to move exclusively forward. <br/>default: `false`                                          |
| point             |           | Set the various waypoints for robot navigation. <br/>default: `$(find simple_nav_goals)/param/point.yaml` |

1. Add permanent workspace environment variables :

   Note: "{TURTLEBOT3_MODEL}" represents the name of the utilized models: "burger", "waffle", or "waffle_pi".
   ```
   echo "export TURTLEBOT3_MODEL={TURTLEBOT3_MODEL}" >> ~/.bashrc
   ```
   ```
   source ~/.bashrc
   ```
2. Launch simulation world and task navigation :

   Note: Execute these two commands separately in different terminal windows.
   ```
   roslaunch tirt_gazebo turtlebot3_tirt.launch
   ```
   ```
   roslaunch simple_nav_goals simple_nav_goals.launch
   ```
   
## References

- Ubuntu install of ROS Noetic (https://wiki.ros.org/noetic/Installation/Ubuntu)
- Install Gazebo using Ubuntu packages (https://classic.gazebosim.org/tutorials?tut=install_ubuntu)
- TurtleBot3 Simulation (https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/)
- SendingSimpleGoals (https://wiki.ros.org/navigation/Tutorials/SendingSimpleGoals)