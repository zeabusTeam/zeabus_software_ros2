// FILE         : connector.hpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, MARCH, 25

#include    <zeabus_sensor/IMU/packet.hpp>

#include    <zeabus_sensor/IMU/LORD_IMU_COMMUNICATION.hpp>

#include    <zeabus_serial/synchronous_port.hpp>

#include    <iostream>
#include    <stdio.h>

#ifndef _ZEABUS_SENSOR_IMU_CONNECTOR_HPP__
#define _ZEABUS_SENSOR_IMU_CONNECTOR_HPP__

namespace zeabus
{

namespace sensor
{

namespace IMU
{

    class Connector : public Packet , public zeabus::serial::SynchronousPort
    {
        public:
            Connector( std::string port_name = "" , unsigned int size = 100 );

            bool set_idle(); // this command will stop stream and set imu ready for setting
            bool ping(); // ping command
            bool resume();
            bool set_IMU_rate( int rate );
            bool set_IMU_message_format( unsigned char first_type , unsigned char second_type
                    , unsigned char thrid_type );
            bool save_IMU_message_format();
            bool enable_IMU_data_stream();
            bool resume();

            bool read_stream();

        protected:
            unsigned char rate;

            void init_header();

            bool read_reply( unsigned char descriptor_byte , int max_round = 1 );

    };

}

}

}

#endif
