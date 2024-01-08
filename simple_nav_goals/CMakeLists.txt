cmake_minimum_required(VERSION 3.0.2)
project(simple_nav_goals)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  move_base_msgs
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES zbar_opencv
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/simple_nav_goals.cpp)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)
