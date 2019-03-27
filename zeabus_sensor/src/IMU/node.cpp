// File         : node.cpp
// Author       : Supasan Komonlit
// CREATE ON    : 27, MARCH 2019

#define _ERROR_TYPE_
#define _CHECK_MEMORY_
#define _PRINT_DATA_CONNECTION_

#include    <zeabus_sensor/IMU/connector.hpp>

#include    <iostream>
#include    <sstdio.h>

int main( int argv , char** argc )
{
    zeabus::sensor::IMU::connector imu("/dev/microstrain/3dm_gx5_45_0000__6251.65903" , 100 );

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
