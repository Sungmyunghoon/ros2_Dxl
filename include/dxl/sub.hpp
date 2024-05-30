#ifndef SUB_HPP
#define SUB_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "dxl/dxl.hpp"

class DxlSubscriber : public rclcpp::Node
{
public:
    DxlSubscriber();
    ~DxlSubscriber();

private:
    void callback(const geometry_msgs::msg::Vector3::SharedPtr msg);

    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr subscription_;
    Dxl dxl_;
};

#endif // SUB_HPP