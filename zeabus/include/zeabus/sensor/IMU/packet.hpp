// FILE         : packet.hpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, MARCH , 22

#include    <vector> // include c++ library for make a buffer to use in main part of packet

#include    <stdio.h> // standard library of c language 
// we include this because we want to use printf
#include    <iostream> // standard library of c++ language

#include    <zeabus/variadic/utilize_vector.hpp>

#ifndef _ZEABUS_SENSOR_IMU_PACKET_HPP__
#define _ZEABUS_SENSOR_IMU_PACKET_HPP__

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

            void push_vector( std::vector<unsigned char>* data_vector ); 

            void print_data( std::string message = "" );

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
