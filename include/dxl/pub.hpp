#ifndef PUB_HPP
#define PUB_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3.hpp"

class DxlPublisher : public rclcpp::Node
{
public:
    DxlPublisher();
    void publish_velocity();

private:
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr publisher_;
    geometry_msgs::msg::Vector3 vel_;
    int vel1_, vel2_;
    int goal1_, goal2_;
};

#endif // PUB_HPP