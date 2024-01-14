#include "std_msgs/String.h"
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <ros/ros.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>
    MoveBaseClient;

int navTable;
double goalLocate[6][2];
std::string zbarCBMsg, zbarLastCBMsg = "";
std::string msg =
  "--------------TIRT--------------\n"
  "|      Enter table number      |\n"
  "|       0         Home         |\n"
  "|       1         Table1       |\n"
  "|       2         Table2       |\n"
  "|       3         Table3       |\n"
  "|       4         Table4       |\n"
  "|       5         Meal         |\n"
  "--------------------------------\n";

void getparam(ros::NodeHandle &nh) {
  nh.getParam("/Home/x", goalLocate[0][0]);
  nh.getParam("/Home/y", goalLocate[0][1]);
  nh.getParam("/Table1/x", goalLocate[1][0]);
  nh.getParam("/Table1/y", goalLocate[1][1]);
  nh.getParam("/Table2/x", goalLocate[2][0]);
  nh.getParam("/Table2/y", goalLocate[2][1]);
  nh.getParam("/Table3/x", goalLocate[3][0]);
  nh.getParam("/Table3/y", goalLocate[3][1]);
  nh.getParam("/Table4/x", goalLocate[4][0]);
  nh.getParam("/Table4/y", goalLocate[4][1]);
  nh.getParam("/Meal/x", goalLocate[5][0]);
  nh.getParam("/Meal/y", goalLocate[5][1]);
}

void nav(int table) {
  MoveBaseClient ac("move_base", true);
  while (!ac.waitForServer(ros::Duration(5.0))) {
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = goalLocate[table][0];
  goal.target_pose.pose.position.y = goalLocate[table][1];
  goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  ac.waitForResult();

  if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Success");
  else
    ROS_INFO("Fail");
}

void zbar(){
  ROS_INFO("Awaiting the scan of the QR code");
  while (true){
    if (zbarLastCBMsg != zbarCBMsg){
      printf("--------------ZBar--------------\n| Callback value : \033[32m%s\033[0m\n", zbarCBMsg.c_str());
      zbarLastCBMsg = zbarCBMsg;
      break;
    }
    ros::spinOnce();
  }
}

void zbarCallback(const std_msgs::String::ConstPtr &msg) {
  zbarCBMsg = msg->data;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "simple_navigation_goals");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("zbar_opencv_code", 1000, zbarCallback);
  while (ros::ok()) {
    // Exemplify the code (Revise it in accordance with the task)
    getparam(nh);
    printf("%s", msg.c_str());
    scanf("%d", &navTable);
    nav(navTable);
    zbar();
  }
  return 0;
}
