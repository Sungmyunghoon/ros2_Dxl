#include "dxl/sub.hpp"

DxlSubscriber::DxlSubscriber()
    : Node("node_dxlsub")
{
    if (!dxl_.open())
    {
        RCLCPP_ERROR(this->get_logger(), "Dynamixel open error");
        rclcpp::shutdown();
        return;
    }

    subscription_ = this->create_subscription<geometry_msgs::msg::Vector3>(
        "topic_dxlpub",
        rclcpp::QoS(rclcpp::KeepLast(10)),
        std::bind(&DxlSubscriber::callback, this, std::placeholders::_1)
    );
}

DxlSubscriber::~DxlSubscriber()
{
    dxl_.close();
}

void DxlSubscriber::callback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received message: %lf, %lf", msg->x, msg->y);
    dxl_.setVelocity(static_cast<int>(msg->x), static_cast<int>(msg->y));
}