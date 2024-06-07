// dxl/pub.hpp와 dxl/dxl.hpp 헤더 파일을 포함
#include "dxl/pub.hpp"
#include "dxl/dxl.hpp"

DxlPublisher::DxlPublisher() // 클래스의 생성자
    : Node("node_dxlpub"), vel1_(0), vel2_(0), goal1_(0), goal2_(0) // 노드의 클래스를 초기화하여 노드 이름을 "node_dxlpub"로 설정
{
    publisher_ = this->create_publisher<geometry_msgs::msg::Vector3>("topic_dxlpub", rclcpp::QoS(rclcpp::KeepLast(10)));
    // 속도 변수(vel1_, vel2_)와 목표 속도(goal1_, goal2_)를 0으로 초기화
    vel_.x = 0;
    vel_.y = 0;
    vel_.z = 0;
}

void DxlPublisher::publish_velocity()
{
    rclcpp::WallRate loop_rate(20.0); // 20Hz -> 50ms publish_velocity 함수는 20Hz(50ms) 주기로 실행

    while (rclcpp::ok())
    {
        if (Dxl::kbhit())
        {
            char c = Dxl::getch();
            switch (c)
            {
            case 's': goal1_ = 0; goal2_ = 0; break;
            case ' ': goal1_ = 0; goal2_ = 0; break;
            case 'f': goal1_ = 50; goal2_ = -50; break;
            case 'b': goal1_ = -50; goal2_ = 50; break;
            case 'l': goal1_ = -50; goal2_ = -50; break;
            case 'r': goal1_ = 50; goal2_ = 50; break;
            default: goal1_ = 0; goal2_ = 0; break;
            }
        }

        // 가속 및 감속 모션 생성
        if (goal1_ > vel1_) vel1_ += 5;
        else if (goal1_ < vel1_) vel1_ -= 5;
        else vel1_ = goal1_;

        if (goal2_ > vel2_) vel2_ += 5;
        else if (goal2_ < vel2_) vel2_ -= 5;
        else vel2_ = goal2_;

        vel_.x = vel1_;
        vel_.y = vel2_;

        RCLCPP_INFO(this->get_logger(), "Publish: %lf, %lf", vel_.x, vel_.y);
        publisher_->publish(vel_);
        loop_rate.sleep();
    }
}
