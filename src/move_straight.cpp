#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"

/*
make the robot go linear
*/

int main(int argc, char** argv){
    ros::init(argc, argv, "straight_node"); //announce that straight node is gonna publish
    ros::NodeHandle n;
    ros::Publisher velocityPub;
    ros::Rate loop_rate(2);

    //we advertise to tell the master to publicize this node publishing Twist messages to the topic
    velocityPub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10); //create our publisher node
    
    geometry_msgs::Twist msg;
    int i =0;

    
    //this is the use case when we want the turtlebot to move a bit

    while (ros::ok())
    {
        msg.linear.x = 12;
        velocityPub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        
    }
    

    return 0;
}
