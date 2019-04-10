//  FILE        : protocol.hpp
//  AUTHOR      : Supasan Komonlit
//  CREATE DATE : 2019, APRIL 10
//  REFERENCE   : This code will write follow old pattern pololu_packet.h but split to two part
//      FILE        : pololu_packet.h
//      AUTHOR      : Mahisorn
//      CREATED ON  : Nov 28, 2014

// Data from this file follow old file and
// reference from https://www.pololu.com/docs/0J40/5.e

#include    <iostream>

#ifndef _ZEABUS_SENSOR_POLOLU_PROTOCOL_HPP__
#define _ZEABUS_SENSOR_POLOLU_PROTOCOL_HPP__

namespace zeabus
{

namespace sensor
{

namespace MAESTRO
{

namespace COMPACT
{

namespace pr

    static const unsigned char SYNC_UART = 0xAA;
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

} // namespace POLOLPU

} // namespace sensor

} // namespace zeabus

#endif // _ZEABUS_SENSOR_POLOLU_PROTOCOL_HPP__
