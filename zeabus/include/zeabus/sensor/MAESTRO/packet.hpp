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

#ifndef _ZEABUS_SENSOR_POLOLU_PACKET_HPP__
#define _ZEABUS_SENSOR_POLOLU_PACKET_HPP__

namespace zeabus
{
namespace sensor
{
namespace MAESTRO
{

    class Packet
    {
        public:

            Packet( unsigned char sync );

            void begin_packet( uint8_t device_id , uint8_t command );

            std::vector< unsigned char > buffer;

    
    }; // class Packet

} // namespace POLOLU

} // namespace sensor

} // namespace zeabus

#endif // _ZEABUS_SENSOR_POLOLU_PACKET_HPP__
