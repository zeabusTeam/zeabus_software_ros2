// File         : node.cpp
// Author       : Supasan Komonlit
// CREATE ON    : 27, MARCH 2019

#define _ERROR_TYPE_
#define _CHECK_MEMORY_
#define _PRINT_DATA_CONNECTION_

#define _DECLARE_PROCESS_
#define _PRINT_DATA_STREAM_

#include    <zeabus/sensor/IMU/connector.hpp>

#include    <zeabus/sensor/IMU/LORD_IMU_COMMUNICATION.hpp>

#include    "rclcpp/rclcpp.hpp"
#include    "sensor_msgs/msg/imu.hpp"

#include    <iostream>
#include    <stdio.h>

namespace Asio = boost::asio;
namespace IMUProtocal = zeabus::sensor::IMU::LORD_MICROSTRAIN;

int main( int argv , char** argc )
{
    zeabus::sensor::IMU::Connector imu("/dev/microstrain/3dm_gx5_45_0000__6251.65903" , 100 );

#ifdef _DECLARE_PROCESS_
    printf("Finish declare imu object\n");
#endif

    bool status_file = true ; // use collect response of function
    bool skip_process = false; // use to don't do that process and don't alert
    unsigned int round = 0;
    unsigned int limit_round = 6; // if you want to try n round set limit_round = n + 1

    status_file = imu.open_port();
    if( ! status_file )
    {
        printf("Failure to open port imu\n");
        skip_process = true;
    }
#ifdef _DECLARE_PROCESS_
    else{
        printf("Finish open_port process\n");
    }
#endif // _DECLARE_PROCESS_

	(void)imu.set_option_port( Asio::serial_port_base::flow_control( 
							Asio::serial_port_base::flow_control::none ) );
	(void)imu.set_option_port( Asio::serial_port_base::parity( 
							Asio::serial_port_base::parity::none ) );
	(void)imu.set_option_port( Asio::serial_port_base::stop_bits( 
							Asio::serial_port_base::stop_bits::one ) );
	(void)imu.set_option_port( Asio::serial_port_base::character_size( (unsigned char) 8 ) );

#ifdef _DECLARE_PROCESS_
    printf("Finish setup port of imu\n");
#endif // _DECLARE_PROCESS_

    round = 0; // set init value counter is 0 for start process
    while( ! skip_process )
    {
        round++;
        status_file = imu.set_idle(); // try to set imu to idle state
        if( ! status_file )
        {
            printf("round %d : Failure command set idle\n" , round );
        }
        else
        {
            printf("round %d : Success command set idle\n\n" , round );
            break; // jump success this process
        }
        if( round == limit_round )
        {
            skip_process = true;
        }
    }

    round = 0; // set init value counter is 0 for start process
    while( ! skip_process )
    {
        round++;
        status_file = imu.ping();
        if( ! status_file )
        {
            printf("round %d : Failure command ping\n" , round );
        }
        else
        {
            printf("round %d : Success command ping\n\n" , round );
            break; // jump sunccess this process
        }
        if( round == limit_round )
        {
            skip_process = true;
        }
    }

    imu.set_IMU_rate( 100 ); // send in mode Rate Decimation = IMU Base Rate / Desired Data Rate

    round = 0;
    while( ! skip_process )
    {
        round++;
        status_file = imu.set_IMU_message_format( 
                IMUProtocal::DATA::IMU_DATA_SET::SCALED_ACCELEROMETER_VECTOR 
                , IMUProtocal::DATA::IMU_DATA_SET::SCALED_GYRO_VECTOR
                , IMUProtocal::DATA::IMU_DATA_SET::CF_QUATERNION );
        if( ! status_file )
        {
            printf("round %d : Failure command set IMU message format\n" , round );
        }
        else
        {
            printf("round %d : Success command set IMU message format\n" , round );
            break;
        }
        if( round == limit_round )
        {
            skip_process = true;
        }
    }
    // we not save because we have new set up always want to use

    round = 0;
    while( ! skip_process )
    {
        round++;
        status_file = imu.enable_IMU_data_stream();
        if( ! status_file )
        {
            printf("round %d : Failure command set enable IMU data stream\n" , round );
        }
        else
        {   
            printf("round %d : Success command set enable IMU data stream\n" , round );
            break;
        }
        if( round == limit_round )
        {
            skip_process = true;
        }
    }

    round = 0;
    while( ! skip_process )
    {
        round++;
        status_file = imu.resume();
        if( ! status_file )
        {
            printf("round %d : Failure command resume data stream\n" , round );
        }
        else
        {
            printf("round %d : Success command resume data stream\n" , round );
        }
        if( round == limit_round )
        {
            skip_process = true;
        }
    }

#ifdef _DECLARE_PROCESS_
    printf( "Now setup object for ROS Mode\n");
#endif // _DECLARE_PROCESS_
    auto node = rclcpp::Node::make_shared("imu_data");
    auto publisher = node->create_publisher< sensor_msgs::msg::Imu >("/sensor/imu");
    auto message = std::make_shared< sensor_msgs::msg::Imu >();
    rclcpp::WallRate loop_rate( 50 );

#ifdef _DECLARE_PROCESS_
    printf( "Now start streaming data\n" );
#endif // _DECLARE_PROCESS_
    
    while( rclcpp::ok() && (! skip_process) )
    {
        status_file = imu.read_stream();
        if( status_file )
        {
#ifdef _PRINT_DATA_STREAM_
            imu.print_data( "IMU message " );
#endif // _PRINT_DATA_STREAM_
        }
        else
        {
            printf( "<--- IMU ---> BAD DATA\n\n");
        }
        loop_rate.sleep();
    }
    rclcpp::shutdown();

    round = 0; // set init value counter is 0 for start process
    while( ! skip_process )
    {
        round++;
        status_file = imu.set_idle(); // try to set imu to idle state
        if( ! status_file )
        {
            printf("round %d : Failure command set idle\n" , round );
        }
        else
        {
            printf("round %d : Success command set idle\n\n" , round );
            break; // jump success this process
        }
        if( round == limit_round )
        {
            skip_process = true;
        }
    }

    imu.close_port();

    return 0;
}
