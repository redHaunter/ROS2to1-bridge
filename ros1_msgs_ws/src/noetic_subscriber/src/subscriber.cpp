#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/Imu.h"

class Republisher
{
public:
  Republisher(ros::NodeHandle& nh) : nh_(nh)
  {
    sub_left = nh_.subscribe("cam0/image_raw", 10, &Republisher::nullFuncImg, this);
    sub_right = nh_.subscribe("cam1/image_raw", 10, &Republisher::nullFuncImg, this);
    sub_imu = nh_.subscribe("imu0", 10, &Republisher::nullFuncIMU, this);
  }

  void nullFuncImg(const sensor_msgs::Image::ConstPtr& msg){}
  void nullFuncIMU(const sensor_msgs::Imu::ConstPtr& msg){}

private:
  ros::NodeHandle nh_;
  ros::Subscriber sub_left;
  ros::Subscriber sub_right;
  ros::Subscriber sub_imu;
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "noetic_subscriber_republisher");
  ros::NodeHandle nh;

  Republisher republisher(nh);

  ros::spin();

  return 0;
}
