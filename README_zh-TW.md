# Simple-Navigation-Goals

[![License: CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC_BY--NC--SA_4.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc-sa/4.0/)
![ROS](https://img.shields.io/badge/ROS-Noetic-blue)
[![Robot](https://img.shields.io/badge/Robot-TurtleBot3-brightgreen)](https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/#gazebo-simulation)

<kbd> <br> [English][en] <br> </kbd>
<kbd> <br> [简体中文][zh-CN] <br> </kbd>
<kbd> <br> 繁體中文 <br> </kbd>

[en]: README.md
[zh-CN]: README_zh-CN.md

"simple_nav_goals" 為用於任務導航的 ROS 軟體套件。

## 軟體需求

- Turtlebot3
   ```
   sudo apt-get install ros-noetic-turtlebot3*
   ```
- DWA Local Planner
   ```
   sudo apt-get install ros-noetic-dwa-local-planner*
   ```

## 安裝並建置

1. 導覽至您的 catkin 工作空間內的「src」目錄：
   ```
   cd ~/catkin_ws/src
   ```
2. 從 GitHub 複製 simple_nav_goals 套件至本地端：

   - 程式語言

      - C++
        ```
        git clone https://github.com/wenjiu2001/Simple-Navigation-Goals.git simple_nav_goals
        ```
      - Python
        ```
        git clone -b python-devel https://github.com/wenjiu2001/Simple-Navigation-Goals.git simple_nav_goals
        ```
3. 建置 simple_nav_goals 套件：
   ```
   cd ~/catkin_ws && catkin_make
   ```
4. 套件環境設定：
   ```
   source ./devel/setup.sh
   ```

## 使用方法

透過修改以下參數可以進行調整：

| 參數名稱          | 資料類型 | 詳細資訊                                                                              |
| ----------------- | -------- | ------------------------------------------------------------------------------------- |
| model             | 字串     | 設定Turtlebot3機器人模型。 <br/>預設值：`null`                                        |
| map_file          |          | 設定機器人導航的地圖和參數。 <br/>預設值：`$(find simple_nav_goals)/map/map.yaml`     |
| open_rviz         | 布林值   | 設定是否啟動RViz。 <br/>預設值：`true`                                                |
| move_forward_only | 布林值   | 設定機器人為僅能向前直行。 <br/>預設值：`false`                                       |
| point             |          | 設定機器人導航的多個路徑點。 <br/>預設值：`$(find simple_nav_goals)/param/point.yaml` |

1. 新增永久性工作空間環境變量：

   - Turtlebot3模型

      - Burger
        ```
        echo "export TURTLEBOT3_MODEL=burger" >> ~/.bashrc
        ```
      - Waffle
        ```
        echo "export TURTLEBOT3_MODEL=waffle" >> ~/.bashrc
        ```
      - Waffle Pi
        ```
        echo "export TURTLEBOT3_MODEL=waffle_pi" >> ~/.bashrc
        ```
   - 重新載入 .bashrc 文件
     ```
     source ~/.bashrc
     ```
2. 啟動模擬世界和任務導航：

   註：請分別在不同的終端機視窗中執行這兩個指令。
   ```
   roslaunch tirt_gazebo turtlebot3_tirt.launch
   ```
   ```
   roslaunch simple_nav_goals simple_nav_goals.launch
   ```
   
## 參考資料

- [在Ubuntu上安裝ROS Noetic](https://wiki.ros.org/noetic/Installation/Ubuntu)
- [使用Ubuntu套件安裝Gazebo](https://classic.gazebosim.org/tutorials?tut=install_ubuntu)
- [TurtleBot3 模擬](https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/)
- [傳送簡單目標](https://wiki.ros.org/navigation/Tutorials/SendingSimpleGoals)