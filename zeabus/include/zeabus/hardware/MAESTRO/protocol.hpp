//  FILE        : protocol.hpp
//  AUTHOR      : Supasan Komonlit
//  CREATE DATE : 2019, APRIL 10
//  REFERENCE   : This code will write follow old pattern pololu_packet.h but split to two part
//      FILE        : pololu_packet.h
//      AUTHOR      : Mahisorn
//      CREATED ON  : Nov 28, 2014

// Data from this file follow old file and
// reference from https://www.pololu.com/docs/0J40/5.e

// Warning we use unsigned char because that is data 1 byte or 8 bit
// Reference : http://www.cplusplus.com/doc/tutorial/variables/

#include    <iostream>

#ifndef _ZEABUS_HARDWARE_MAESTRO_PROTOCOL_HPP__
#define _ZEABUS_HARDWARE_MAESTRO_PROTOCOL_HPP__

namespace zeabus
{

namespace hardware
{

namespace MAESTRO
{

namespace protocol
{

namespace POLOLU
{


    static const unsigned char BASE_PROTOCOL = 0xAA ; // use first of packet
    static const unsigned char COMMAND_SET_TARGET = 0x04;
    static const unsigned char COMMAND_SET_MULTIPLE_TARGETS = 0x1F;
    static const unsigned char COMMAND_SET_SPEED = 0x07;
    static const unsigned char COMMAND_SET_ACCELERATION = 0x09;
    static const unsigned char COMMAND_SET_PWM = 0x0A;
    static const unsigned char COMMAND_GET_POSITION = 0x10;
    static const unsigned char COMMAND_GET_MOVING_STATE = 0x13;
    static const unsigned char COMMAND_GET_ERROR = 0x21;
    static const unsigned char COMMAND_GO_HOME = 0x22;

} // namespace POLOLU

namespace COMPACT
{

    static const unsigned char COMMAND_SET_TARGET = 0x84;
    static const unsigned char COMMAND_SET_MULTIPLE_TARGET = 0x9F;
    static const unsigned char COMMAND_SET_SPEED = 0x87;
    static const unsigned char COMMAND_SET_ACCELERATION = 0x89;
    static const unsigned char COMMAND_SET_PWM = 0x8A;
    static const unsigned char COMMAND_GET_POSITION = 0x90;
    static const unsigned char COMMAND_GET_MOVING_STATE = 0x93;
    static const unsigned char COMMAND_GET_ERROR = 0xA1;
    static const unsigned char COMMAND_GO_HOME = 0xA2;

} // namespace COMPACT

} // namespace protocol

} // namespace MAESTRO

} // namespace hardware

} // namespace zeabus

#endif // _ZEABUS_SENSOR_POLOLU_PROTOCOL_HPP__
