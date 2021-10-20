/*
this is the code developed in order to
make a publisher node that makes
a turtlebot go in circles 
*/

#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"

/*
void velCallback(const geometry_msgs::Twist::ConstPtr& msg){
    
    geometry_msgs::Twist vel = *msg;
    
    if (vel.linear.x > 1.8){
        vel.linear.x = 1.8;
    }

    velocityPub.publish(vel);
}
*/

int main(int argc, char** argv){
    ros::init(argc, argv, "circler_node");
    ros::NodeHandle n;
    ros::Publisher velocityPub;
    ros::Rate loop_rate(20);

    //we advertise to tell the master to publicze this node publishing messages to the topic
    velocityPub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10); //create our publisher node
    
    geometry_msgs::Twist msg;
    msg.linear.x = 12.0;
    velocityPub.publish(msg);
    ros::spin();
    loop_rate.sleep();
    return 0;

}
