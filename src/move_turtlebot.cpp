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

    
    float goals[2][3] = {{-2.0, 0.0, 1.57}, {0.0, 0.0, 1.57}}
    for (int i = 0; i < 2; i++){
        goal.target_pose.pose.position.x = goals[i][0];
        goal.target_pose.pose.position.y = goals[i][1];
        goal.target_pose.pose.position.w = goals[i][2];

        //send the goal position and orientation (w) for robot to reach
        ROS_INFO("Sending Goal");
        ac.sendGoal(goal);

        //wait infinite time for results
        ac.waitForResult();

        ros::Duration(5.0).sleep();
    }

    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) ROS_INFO("We have reached our destination!");
    
    else ROS_INFO("The base failed to move forward");

    return 0;
}