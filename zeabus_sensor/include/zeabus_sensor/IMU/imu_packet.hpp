// FILE         : imu_packet.hpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, MARCH , 22

#include    <vector> // include c++ library for make a buffer to use in main part of packet

#include    <stdio.h> // standard library of c language 
// we include this because we want to use printf
#include    <iostream> // standard library of c++ language

#ifndef _ZEABUS_SENSOR_IMU_IMU_PACKET_HPP__
#define _ZEABUS_SENSOR_IMU_IMU_PACKET_HPP__

namespace zeabus
{

namespace sensor
{

namespace IMU
{

    class Packet
    {
        public:
            Packet( unsigned int size = 100 );

            void print_check_memory(); // this function for check about size of vector

            bool check_sum( bool self_check = true );

            void add_check_sum();

            void find_check_sum( unsigned int last_data ); 

            void fit_capacity();

            void clear_member();

            void resize( unsigned int size );

            void reserve( unsigned int size );

            // For push data we use pattern of variadic function
            template< typename type_single >
            void push_data( type_single data_single );

            template< typename type_single , typename... type_pack >
            void push_data( type_single data_single , type_pack... data_pack );

        protected:
            std::vector< unsigned char > data; // use to collect buffer
 
            unsigned long int data_4_byte( int offset ); 
            // use this when you want to add 4 byte or 4 member to one variable

            unsigned char MSB;
            unsigned char LSB;

    };

}

}

}

#endif
