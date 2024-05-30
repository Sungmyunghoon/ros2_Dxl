#include "dxl/pub.hpp"
#include <memory>

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DxlPublisher>();
    node->publish_velocity();
    rclcpp::shutdown();
    return 0;
}