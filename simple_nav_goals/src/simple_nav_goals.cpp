#include "std_msgs/String.h"
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <ros/ros.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>
    MoveBaseClient;

int navTable;
std::string locations[] = {"/Home", "/Table1", "/Table2", "/Table3", "/Table4", "/Meal"};
double goalLocate[6][2];
std::string zbarCBMsg, zbarLastCBMsg = "";
const char* msg = 
  "--------------TIRT--------------\n"
  "|  Number   Name       Point    \n"
  "|    0      Home    %.2f  %.2f  \n"
  "|    1     Table1   %.2f  %.2f  \n"
  "|    2     Table2   %.2f  %.2f  \n"
  "|    3     Table3   %.2f  %.2f  \n"
  "|    4     Table4   %.2f  %.2f  \n"
  "|    5      Meal    %.2f  %.2f  \n"
  "--------------------------------\n";

void getparam(ros::NodeHandle &nh) {
  for (int i = 0; i < 6; ++i) {
    std::string paramNameX = locations[i] + "/x";
    std::string paramNameY = locations[i] + "/y";
    nh.getParam(paramNameX, goalLocate[i][0]);
    nh.getParam(paramNameY, goalLocate[i][1]);
  }
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
    printf(msg,
           goalLocate[0][0], goalLocate[0][1],
           goalLocate[1][0], goalLocate[1][1],
           goalLocate[2][0], goalLocate[2][1],
           goalLocate[3][0], goalLocate[3][1],
           goalLocate[4][0], goalLocate[4][1],
           goalLocate[5][0], goalLocate[5][1]);
    scanf("%d", &navTable);
    nav(navTable);
    zbar();
  }
  return 0;
}
