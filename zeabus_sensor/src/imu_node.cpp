// File         : imu_node.cpp
// Author       : Supasan Komonlit
// CREATE ON    : 27, MARCH 2019

#define _DECLARE_PROCESS_
#define _PRINT_DATA_STREAM_

#include    "rclcpp/rclcpp.hpp"

#include    <zeabus/sensor/IMU/connector.hpp>

#include    <zeabus/sensor/IMU/LORD_IMU_COMMUNICATION.hpp>

#include    <zeabus/convert/vector/one_byte.hpp>

#include    <zeabus/service/base_get_sensor_data.hpp>

#include    <zeabus/srv/get_sensor_imu.hpp>

#include    "sensor_msgs/msg/imu.hpp"

#include    <iostream>
#include    <chrono>
#include    <vector>

typedef zeabus::service::BaseGetSensorData< zeabus::srv::GetSensorImu 
            , zeabus::srv::GetSensorImu::Request , zeabus::srv::GetSensorImu::Response 
            , sensor_msgs::msg::Imu> type_imu_service;

namespace Asio = boost::asio;
namespace IMUProtocal = zeabus::sensor::IMU::LORD_MICROSTRAIN;

int main( int argv , char** argc )
{
    zeabus::sensor::IMU::Connector imu("/dev/microstrain/3dm_gx5_45_0000__6251.65901" , 100 );

#ifdef _DECLARE_PROCESS_
    std::cout << "Finish declare imu object\n";
#endif // _DECLARE_PROCESS_

    bool status_file = true ; // use collect response of function
    bool skip_process = false; // use to don't do that process and don't alert
    unsigned int round = 0;
    unsigned int limit_round = 6; // if you want to try n round set limit_round = n + 1

    status_file = imu.open_port();
    if( ! status_file )
    {
        std::cout << "Failure to open port imu\n";
        skip_process = true;
    }
#ifdef _DECLARE_PROCESS_
    else{
        std::cout << "Finish open_port process\n";
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
    std::cout << "Finish setup port of imu\n";
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
        if( round == (limit_round * 20) )
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
            break;
        }
        if( round == limit_round )
        {
            skip_process = true;
        }
    }

#ifdef _DECLARE_PROCESS_
    printf( "Now setup object for ROS Mode\n");
#endif // _DECLARE_PROCESS_
    sensor_msgs::msg::Imu message;
    message.header.frame_id = "imu";
    rclcpp::init( argv , argc ); // use one time only

    type_imu_service imu_service( "imu_node" , "/sensor/imu");
    imu_service.register_data( &message );
    (void)imu_service.prepare_spin();

    std::shared_ptr< type_imu_service > pointer_imu_service( &imu_service );

#ifdef _DECLARE_PROCESS_
    printf( "Now start streaming data\n" );
#endif // _DECLARE_PROCESS_

    unsigned int limit_number;    
    while( ( rclcpp::ok() && ( ! skip_process ) ) )
    {
#ifdef _PRINT_DATA_STREAM_
        printf("Read data form IMU\n");
#endif // _PRINT_DATA_STREAM_
        status_file = imu.read_stream();
        if( status_file )
        {
#ifdef _PRINT_DATA_STREAM_
            imu.print_data( "IMU message " );
#endif // _PRINT_DATA_STREAM_
            if( imu.access_data(2) != 0x80 ) // Desciptor set byte of data stream is 0x80
            {
                std::cout << "This not packet for data stream skip out\n";
                continue;
            }
            printf( "<--- IMU ---> GOOD DATA\n\n");
            // start at position 5 indent 0 1 2 3  
            // because 0 - 4 is header and description of data packet
            // pattern of packet for 0 1 2 3 4 are u e DESC_Packet Payload_length Field_length
            limit_number = imu.size_member() - 2 ;
            for( unsigned int run = 5 ; ( run < limit_number ) && ( ! skip_process ) ; )
            {
                switch (imu.access_data( run ) )
                {
                case IMUProtocal::DATA::IMU_DATA_SET::SCALED_ACCELEROMETER_VECTOR :
                    zeabus::convert::vector::one_byte::vector3( &(imu.data) 
                            , &(message.linear_acceleration) , run + 1);
                    run += 14 ; // skip to point start data < 1 byte >
                                // skip to point legth data 3 floats < 12 bytes >
                                // skip for next field length < 1 byte>
                                // this will make run will point to next descriptor
                    break;
                case IMUProtocal::DATA::IMU_DATA_SET::SCALED_GYRO_VECTOR :
                    zeabus::convert::vector::one_byte::vector3( &(imu.data) 
                            , &(message.angular_velocity) , run + 1);
                    run += 14 ; // skip to point start data < 1 byte >
                                // skip to point legth data 3 floats < 12 bytes >
                                // skip for next field length < 1 byte>
                                // this will make run will point to next descriptor
                    break;
                case IMUProtocal::DATA::IMU_DATA_SET::CF_QUATERNION :
                    zeabus::convert::vector::one_byte::quaternion( &(imu.data) 
                            , &(message.orientation) , run + 1);
                    run += 18 ; // skip to point start data < 1 byte >
                                // skip to point legth data 4 floats < 12 bytes >
                                // skip for next field length < 1 byte>
                                // this will make run will point to next descriptor
                    break;
                default :
                    printf("Switch case error for convert bits data to ros message\n");
                    skip_process = true;
                    break;
                }
                message.header.stamp = rclcpp::Time(); 
            } // loop for of get data
        } // condition have packet of data stream
        else
        {
            printf( "<--- IMU ---> BAD DATA\n\n");
        }
#ifdef _PRINT_DATA_STREAM_
        std::cout << "Before spin\n" ;
#endif // _PRINT_DATA_STREAM_
        rclcpp::spin_some( pointer_imu_service );
#ifdef _PRINT_DATA_STREAM_
        std::cout << "After spin\n" ;
#endif // _PRINT_DATA_STREAM_
    } // loop while for doing in ros system

    rclcpp::shutdown();

    round = 0; // set init value counter is 0 for start process
    while( imu.port_is_open() ) //
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
    }

    printf("Now close port of imu\n");
    imu.close_port();

    return 0;
}
