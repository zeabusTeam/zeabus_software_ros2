//  FILE        : packet.hpp
//  AUTHOR      : Supasan Komonlit
//  CREATE DATE : 2019, APRIL 10
//  REFERENCE   : This code will write follow old pattern pololu_packet.h but split to two part
//      FILE        : pololu_packet.h
//      AUTHOR      : Mahisorn
//      CREATED ON  : Nov 28, 2014

#include    <iostream>

#include    <vector> //  include vector for make buffer

#include    <zeabus/variadic/utilize_vector.hpp>

#include    <zeabus/hardware/MAESTRO/protocol.hpp>

// This file will make packet protocol for connect to pololu
// Reference packet :
//      link 1 command protocol : https://www.pololu.com/docs/0J40/5.c 

// Warning we use unsigned char because that is data 1 byte or 8 bit
// Reference : http://www.cplusplus.com/doc/tutorial/variables/

// We use mode UART, detect baud rate

// Format of packet
//  first byte always is 0xAA for init packet
//  second byte for Device Number. In default is 12 ( 0x0B )

// Format individual packet of command
// Reference https://www.pololu.com/docs/0J40/5.e

#ifndef _ZEABUS_HARDWARE_MAESTRO_PACKET_HPP__
#define _ZEABUS_HARDWARE_MAESTRO_PACKET_HPP__

namespace zeabus
{
namespace hardware
{
namespace MAESTRO
{

    class BasePacket // for future base packet of two protocol connect MAESTRO
    {
        public:
            void print_check_memory(); // this function for check detail size of vector

            void fit_capacity(); // function std::vector::shrink_to_fit
    
            void clear_member(); // We will clear only size of member to 0

            void resize( unsigned int size ); // function std::vector::resize
        
            void reserve( unsigned int size ); // function std::vector::reserve

            void print_data( std::string message = "" ); // to print all member of vector
        
        protected:
            BasePacket( unsigned int reserve_size = 100 );
            std::vector< unsigned char > data;
    }; // class BasePacket

namespace POLOLU
{
    class Packet : public zeabus::hardware::MAESTRO::BasePacket
    {
        public:

            Packet( unsigned char init_byte 
                    = zeabus::hardware::MAESTRO::protocol::POLOLU::BASE_PROTOCOL 
                    , unsigned char device_number = 0x0C , unsigned int reserve_size = 100 );

            void set_init_byte( unsigned char init_byte );
            void set_device_number( unsigned char device_number );

            void init_header( unsigned char command );

            void push_vector_2_bytes( std::vector< unsigned short int >* data ); 

        protected:
            unsigned char init_byte;
            unsigned char device_number;

    }; // class Packet

} // namespace POLOLU

} // namespace MAESTRO

} // namespace hardware

} // namespace zeabus

#endif // _ZEABUS_SENSOR_POLOLU_PACKET_HPP__
