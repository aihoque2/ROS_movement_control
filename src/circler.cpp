/*
this is the code developed in order to
make a publisher node that makes
a turtlebot go in circles 
*/

#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"

void doCircle(const nav_msgs::Odometry::ConstPtr& msg){
    double x = msg->pose.pose.position.x;
    double y = msg->pose.pose.position.y;
    ROS_INFO("x: %f, y: %f", x, y);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "circler");
    ros::NodeHandle n;
    ros::Publisher velocityPub = n.advertise<geometry_msgs::Twist>("/cmd_vel/", 1); //create our publisher node
    geometry_msgs::Twist base_cmd;

    base_cmd.linear.x = 3.0;
    while(ros::ok){
        velocityPub.publish(base_cmd);
        ros::spin();
    }

}
