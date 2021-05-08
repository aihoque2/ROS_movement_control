/*
this is the code developed in order to
make a publisher node that makes
a turtlebot go in circles 
*/

#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"

ros::Publisher velocityPub;

void velCallback(const geometry_msgs::Twist::ConstPtr& msg){
    
    geometry_msgs::Twist vel = *msg;
    
    if (vel.linear.x > 1.8){
        vel.linear.x = 1.8;
    }

    velocityPub.publish(vel);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "circler_node");
    ros::NodeHandle n;
    velocityPub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10); //create our publisher node
    ros::Subscriber sub = n.subscribe("/cmd_vel", 10, velCallback);
    ros::spin();
    return 0;

}
