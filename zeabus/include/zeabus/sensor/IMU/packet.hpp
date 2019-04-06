// FILE         : packet.hpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, MARCH , 22

#include    <vector> // include c++ library for make a buffer to use in main part of packet

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

            // this function use to check_sum in pattern of IMU Protocol
            //   parameter self_check if true we will find MSB and LSB for checking
            //      if false we will compare with this->MSB and this->LSB without calculate
            bool check_sum( bool self_check = true );

            // this function will to calculate checksome by current size of member
            // and push to data buffer
            void add_check_sum();

            // this will find check sum in pattern of IMU LORD MICROSTRAIN Protocore
            // parameter size_data will assign size to check sum
            // situation 1 :
            //      if you have reply packet size 10 you want to check checksum
            //      you please assign this parameter have value 8 
            //      that will calculate checksome 0 - 7  for you
            // situation 2 :
            //      if you have command packet size 10 you want to find checksum for add
            //      you please assign this paramter have value 10
            void find_check_sum( unsigned int size_data ); 

            // this will you shrink_to_fit function for reallocate memory
            void fit_capacity();

            // this will delete you all data on packet
            void clear_member();

            void resize( unsigned int size );

            void reserve( unsigned int size );

            // push_vector ue for push data vector type
            void push_vector( std::vector<unsigned char>* data_vector ); 

            void print_data( std::string message = "" );

            unsigned int size_member();

            unsigned char access_data( unsigned int position );
            // for access_data in data <protected mode>
            
            std::vector< unsigned char > data; // use to collect buffer

        protected:
 
            unsigned long int data_4_byte( int offset ); 
            // use this when you want to add 4 byte or 4 member to one variable

            unsigned char MSB;
            unsigned char LSB;

    };

}

}

}

#endif
