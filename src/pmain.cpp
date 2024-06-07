#include "dxl/pub.hpp" // DxlPublisher 클래스를 포함하기 위한 헤더 파일
#include <memory> // 스마트 포인터 사용을 위한 헤더 파일

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv); // ROS2 시스템을 초기화
    auto node = std::make_shared<DxlPublisher>(); // 클래스의 인스턴스를 생성
    node->publish_velocity(); // 노드의 메서드를 호출
    rclcpp::shutdown();
    return 0;
}
