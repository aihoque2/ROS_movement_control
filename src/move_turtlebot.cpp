/*
this is the code developed in order to
make a publisher node that uses move_base
to move turtlebot to a point
*/
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

//client to send goal requests to move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char**argv){
    ros::init(argc, argv, "move_turtlebot")
    
    //tell action client we want to spin a thread by default
    MoveBaseClient ac("move_base", true);

    while(!ac.waitForServer(ros::Duration(5.0))){
        ROS_INFO("waiting for the move_base action server to come up");
    }

    move_base_msgs::MoveBaseGoal goal;

    //set up frame parameters
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    /*TODO
    float goals
    goal.target_pose.pose.position.x = goals[i][0];
    goal.target_pose.pose.position.y = goals[]
    */

    return 0;
}