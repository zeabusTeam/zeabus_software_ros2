// File         : node.cpp
// Author       : Supasan Komonlit
// CREATE ON    : 27, MARCH 2019

#define _ERROR_TYPE_
#define _CHECK_MEMORY_
#define _PRINT_DATA_CONNECTION_

#define _DECLARE_PROCESS_

#include    <zeabus/sensor/IMU/connector.hpp>

#include    <zeabus/sensor/IMU/LORD_IMU_COMMUNICATION.hpp>

#include    <iostream>
#include    <stdio.h>

namespace Asio = boost::asio;

int main( int argv , char** argc )
{
    zeabus::sensor::IMU::Connector imu("/dev/microstrain/3dm_gx5_45_0000__6251.65903" , 100 );

#ifdef _DECLARE_PROCESS_
    printf("Finish declare imu object\n");
#endif

    bool status_file = true ; // use collect response of function
    bool skip_process = false; // use to don't do that process and don't alert
    unsigned int round = 0;
    unsigned int limit_round = 5;

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
#endif

	(void)imu.set_option_port( Asio::serial_port_base::flow_control( 
							Asio::serial_port_base::flow_control::none ) );
	(void)imu.set_option_port( Asio::serial_port_base::parity( 
							Asio::serial_port_base::parity::none ) );
	(void)imu.set_option_port( Asio::serial_port_base::stop_bits( 
							Asio::serial_port_base::stop_bits::one ) );
	(void)imu.set_option_port( Asio::serial_port_base::character_size( (unsigned char) 8 ) );

#ifdef _DECLARE_PROCESS_
    printf("Finish setup port of imu\n");
#endif

    round = 0; // set init value counter is 0 for start process
    while( ! skip_process )
    {
        round++;
        status_file = imu.set_idle();
        if( ! status_file )
        {
            printf("round %d : Faile command set idle\n" , round );
        }
        else
        {
            printf("round %d : Success command set idle\n" , round );
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
            printf("round %d : Success command ping\n" , round );
            break; // jump sunccess this process
        }
        if( round == limit_round )
        {
            skip_process = true;
        }
    }

    return 0;
}
