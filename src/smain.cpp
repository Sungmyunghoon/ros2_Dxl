#include "dxl/sub.hpp"
#include <memory>

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DxlSubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}