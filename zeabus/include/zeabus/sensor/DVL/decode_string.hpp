// File         : decode_string.hpp
// Author       : Supasan Komonlit
// Create on    : 2019, APRIL 09

#include    <iostream>

#include    <zeabus/convert/string.hpp>

// This file for decode data from string have response from dvl port
// please ensure before get message to this function
// because we don't check again in function

#ifndef _ZEABUS_SENSOR_DVL_DECODE_STRING_HPP__
#define _ZEABUS_SENSOR_DVL_DECODE_STRING_HPP__

namespace zeabus
{

namespace sensor
{

namespace DVL
{

    // Page 213 BOTTOM-TRACK, SHIP REFERENCCED VELOCITY DATA
    void PD6_code_BS( std::string* message, int* vel_x, int* vel_y, int* vel_z, char* status);

    void PD6_code_BI( std::string* message, int* vel_x, int* vel_y, int* vel_z 
            , int* vel_error , char* status);

} // namespace DVL

} // namespace sensor

} // namespace zeabus

#endif // _ZEABUS_SENSOR_DVL_DECODE_STRING_HPP__
