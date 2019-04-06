// File         : simple_publish.cpp
// Author       : Supasan Komonlit
// Create on    : 2019, APRIL 06

#include    <iostream> // standard library of c++ language

#include    <chrono>

#include    "rclcpp/rclcpp.hpp" // standard ros for c++ language

#include    "std_msgs/msg/int64.hpp"

using namespace std::chrono_literals;

int main( int argv , char** argc)
{
    rclcpp::init( argv , argc );
    rclcpp::Node::SharedPtr simple_node = rclcpp::Node::make_shared("simple_publish");
    
    auto publisher = simple_node->create_publisher< std_msgs::msg::Int64 >("/simple_pub/int64");
    auto message = std::make_shared< std_msgs::msg::Int64>();
    
    rclcpp::WallRate loop_rate( 500ms );
    
    message->data = 0;

    while( rclcpp::ok() )
    {
        RCLCPP_INFO( simple_node->get_logger() , "Publishing : %d\n" , message->data );
        publisher->publish( message ); 
        rclcpp::spin_some( simple_node );
        loop_rate.sleep();
        message->data += 1;
    }
    rclcpp::shutdown();
    return 0;
}
