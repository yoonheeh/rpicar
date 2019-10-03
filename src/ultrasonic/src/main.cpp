#include "ros/ros.h"
#include "std_msgs/Float32.h"

#include <sstream>

/**
 * Mock object for ultrasonic sensor
 */

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::Float32>("ultrasonic_mock", 1000);

  ros::Rate loop_rate(10);

  float sensor_val = 0.0;
  while (ros::ok())
  {
    std_msgs::Float32 msg;

    std::stringstream ss;
    ss << "[test] Mock sensor value:  " << sensor_val;
    msg.data = sensor_val;

    //ROS_INFO("%s", ss.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    sensor_val += 10.0;
    // reset if larger than 100cm
    if (sensor_val > 100)
	sensor_val = 0.0;
  }


  return 0;
}
