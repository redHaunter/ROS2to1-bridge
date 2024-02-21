#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/imu.hpp"
using std::placeholders::_1;

class Publisher : public rclcpp::Node
{
public:
    Publisher()
        : Node("publisher")
    {
        publisher_left = this->create_publisher<sensor_msgs::msg::Image>("cam0/image_raw", 10);
        subscription_left = this->create_subscription<sensor_msgs::msg::Image>(
            "camera_pkg/left/image_raw", 10, std::bind(&Publisher::topic_callback_left, this, _1));
        publisher_right = this->create_publisher<sensor_msgs::msg::Image>("cam1/image_raw", 10);
        subscription_right = this->create_subscription<sensor_msgs::msg::Image>(
            "camera_pkg/right/image_raw", 10, std::bind(&Publisher::topic_callback_right, this, _1));
        publisher_imu = this->create_publisher<sensor_msgs::msg::Imu>("imu0", 10);
        subscription_imu = this->create_subscription<sensor_msgs::msg::Imu>(
            "imu/data_raw", 10, std::bind(&Publisher::topic_callback_imu, this, _1));
    }

private:
    void topic_callback_left(const sensor_msgs::msg::Image::SharedPtr msg) const
    {
        publisher_left->publish(*msg);
    }
    void topic_callback_right(const sensor_msgs::msg::Image::SharedPtr msg) const
    {
        publisher_right->publish(*msg);
    }
    void topic_callback_imu(const sensor_msgs::msg::Imu::SharedPtr msg) const
    {
        publisher_imu->publish(*msg);
    }
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_left;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_left;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_right;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_right;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr publisher_imu;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscription_imu;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Publisher>());
    rclcpp::shutdown();
    return 0;
}