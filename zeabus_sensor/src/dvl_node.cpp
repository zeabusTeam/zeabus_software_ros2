// File         : dvl_node.cpp
// Author       : Supasan Komonlit
// Create On    : 2019, APRIL 06

#include    <iostream>

#include    <zeabus/serial/synchronous_port.hpp>

#include    "rclcpp/rclcpp.hpp"
#include    "geometry_msgs/msg/twist_stamped.hpp"

int main( int argv , char** argc )
{
    zeabus::sensor::DVL::Connector dvl("/dev/usb2serial/ftdi_FT2VR5PM_02");

    bool status_file = true; // if true that mean not status are ok

    status_file = dvl.open_port();
    if( status_file )
    {
        std::cout   << "Success to open port dvl\n";
    }
    else
    {
        std::cout   << "Failure to open port dvl\n";
    }

    if( status_file ) // open port is success
    {
        (void)dvl.load_parameter();
        (void)dvl.bottom_track( "001" );
        (void)dvl.max_depth( "0060"); // 5 meter + 1 meter = 6 meter = 60 decimeter
        (void)dvl.set_heading( "00000" );
        (void)dvl.set_salinty( "35" );
        (void)dvl.time_per_ensemble( "00:00:00.00" );
        (void)dvl.time_between_pings( "00:00.05" );
        (void)dvl.ping_per_ensemble( "00000" );
        (void)dvl.data_stream( "6" );
        (void)dvl.save_parameter();
        (void)dvl.resume();
    }

    geometry_msgs::msg::TwistStamped message;
    
    rclcpp::init( argv , argc );
    rclcpp::Node::SharedPtr dvl_node = rclcpp::Node::make_shared("dvl_node");

    
    
}
