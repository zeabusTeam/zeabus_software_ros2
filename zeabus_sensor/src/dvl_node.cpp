// File         : dvl_node.cpp
// Author       : Supasan Komonlit
// Create On    : 2019, APRIL 06

#include    <iostream>

#include    <zeabus/sensor/DVL/connector.hpp>

#include    <zeabus/sensor/DVL/decode_string.hpp>

#include    <zeabus/service/type_get_01/vector3_stamped.hpp>

#include    "rclcpp/rclcpp.hpp"
#include    "geometry_msgs/msg/vector3_stamped.hpp"

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

    std::string raw_data; // collect data line from port
    std::string type_line; // collect only type of raw_data
    geometry_msgs::msg::Vector3Stamped message;
    message.header.frame_id = "dvl";
    int temp_velocity[4] = { 0 , 0 , 0 , 0 }; // for collect data from function
    char ok_data;
    
    rclcpp::init( argv , argc );
    rclcpp::Node::SharedPtr dvl_node = rclcpp::Node::make_shared("dvl_node");

    zeabus::service::type_get_01::Vector3Stamped sender( &dvl_node );
    auto server_sender = sender.create_service( &message , "/sensor/dvl" );

    while( status_file )
    {
        (void)dvl.read_data( &raw_data );
        type_line.clear() ; // make string are empty
        type_line.push_back( raw_data[1] );
        type_line.push_back( raw_data[2] );
        // get type of data
        if( type_line == "BS" )
        {
            zeabus::sensor::DVL::PD6_code_BS( &raw_data , &(temp_velocity[0]) 
                    , &(temp_velocity[1]) , &(temp_velocity[2]) , &ok_data );
            if( ok_data == 'A' ) // if data BS is ok
            {
                std::cout << "DVL GOOD DATA\n";
                message.vector.x = temp_velocity[0];
                message.vector.y = temp_velocity[1];
                message.vector.z = temp_velocity[2];
                message.header.stamp = rclcpp::Time();
            }
            else
            {
                std::cout << "DVL BAD DATA\n" ;
            }
        } // condition BS data
        rclcpp::spin_some( dvl_node ); 
    } // while loop of ros operating system
    rclcpp::shutdown();

    dvl.close_port();
    
    return 0;
} // function main
