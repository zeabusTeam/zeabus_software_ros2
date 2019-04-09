// File         : string.hpp
// Author       : Supasan Komonlit
// Create on    : 2019, APRIL 9

#include    <iostream>

// This file header have purpose to include file for convert string to another type
// Type available 
//      interger

#ifndef _ZEABUS_CONVERT_STRING_HPP__
#define _ZEABUS_CONVERT_STRING_HPP__

namespace zeabus
{

namespace convert
{

namespace string
{

    bool to_integer( std::string* data , int* result );

}

} // namespace convert

} // namespace zeabus

#endif // _ZEABUS_CONVERT_STRING_HPP__
