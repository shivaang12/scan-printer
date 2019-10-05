#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/qos.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

class ScanPrinter:public rclcpp::Node{
public:
    ScanPrinter():Node("scan_printer"){
        sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "scan",
        rclcpp::QoS(rclcpp::KeepLast(10)),
        std::bind(&ScanPrinter::LaserCallback, this, std::placeholders::_1)
        );
    }

private:
    void LaserCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
        RCLCPP_INFO(this->get_logger(), std::to_string(msg->ranges[90]).c_str());
    }
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr sub_;
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ScanPrinter>());
    rclcpp::shutdown();
    return 0;
}