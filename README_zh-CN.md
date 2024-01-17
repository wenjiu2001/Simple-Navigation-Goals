# Simple-Navigation-Goals

[![License: CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC_BY--NC--SA_4.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc-sa/4.0/)
[![Ubuntu:Focal](https://img.shields.io/badge/Ubuntu-Focal-brightgreen)](https://releases.ubuntu.com/focal/)
[![ROS:Noetic](https://img.shields.io/badge/ROS-Noetic-blue)](https://wiki.ros.org/noetic/Installation/Ubuntu)

<kbd> <br> [English][en] <br> </kbd>
<kbd> <br> 简体中文 <br> </kbd>
<kbd> <br> [繁體中文][zh-TW] <br> </kbd>

[en]: README.md
[zh-TW]: README_zh-TW.md

"simple_nav_goals" 为用于任务导航的 ROS 软件包。

## 软件依赖

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

## 安装并构建

1. 导航至您的 catkin 工作空间内的「src」目录：
   ```
   cd ~/catkin_ws/src
   ```
2. 从 GitHub 克隆 simple_nav_goals 包至本地端：
   ```
   git clone https://github.com/wenjiu2001/Simple-Navigation-Goals.git simple_nav_goals
   ```
3. 构建 simple_nav_goals 包：
   ```
   cd ~/catkin_ws && catkin_make
   ```
4. 包环境设置：
   ```
   source ./devel/setup.sh
   ```

## 使用方法

通过修改以下参数可以进行调整：

| 参数名称          | 数据类型 | 详细信息                                                                              |
| ----------------- | -------- | ------------------------------------------------------------------------------------- |
| model             | 字符串   | 设置Turtlebot3机器人模型。 <br/>默认值：`null`                                        |
| map_file          |          | 设置机器人导航的地图和参数。 <br/>默认值：`$(find simple_nav_goals)/map/map.yaml`     |
| open_rviz         | 布尔值   | 设置是否启动RViz。 <br/>默认值：`true`                                                |
| move_forward_only | 布尔值   | 设置机器人为仅能向前直行。 <br/>默认值：`false`                                       |
| point             |          | 设置机器人导航的多个路径点。 <br/>默认值：`$(find simple_nav_goals)/param/point.yaml` |

1. 添加永久性工作空间环境变量：

   注：「{TURTLEBOT3_MODEL}」代表所使用的模型名称：「burger」、「waffle」或「waffle_pi」。
   ```
   echo "export TURTLEBOT3_MODEL={TURTLEBOT3_MODEL}" >> ~/.bashrc
   ```
   ```
   source ~/.bashrc
   ```
2. 启动模拟世界和任务导航：

   注：请分别在不同的终端窗口中执行这两个命令。
   ```
   roslaunch tirt_gazebo turtlebot3_tirt.launch
   ```
   ```
   roslaunch simple_nav_goals simple_nav_goals.launch
   ```
   
## 参考资料

- Ubuntu install of ROS Noetic (https://wiki.ros.org/noetic/Installation/Ubuntu)
- Install Gazebo using Ubuntu packages (https://classic.gazebosim.org/tutorials?tut=install_ubuntu)
- TurtleBot3 Simulation (https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/)
- SendingSimpleGoals (https://wiki.ros.org/navigation/Tutorials/SendingSimpleGoals)