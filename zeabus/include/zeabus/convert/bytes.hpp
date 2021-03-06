// FILE         : bytes.hpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, APRIL 01

#include    <iostream>

#include    <cstring> // import for function memcpy

#include    <vector>

// This file create for convert data bytes to variable type int / float or double up to you 
// But ensure you have to study about size of type varaible and your data that are correct
// for size of type varaible we reference from http://www.cplusplus.com/doc/tutorial/variables/

#ifndef _ZEABUS_CONVERT_BYTES_HPP__
#define _ZEABUS_CONVERT_BYTES_HPP__

namespace zeabus
{

namespace convert
{

namespace bytes
{

    // float have design to have size is 4 bytes that make me use for imu packet
    // because 1 variable have 4 bytes 
    bool vector_to_float( std::vector<unsigned char>* set_data 
            , float* answer , unsigned int offset = 0 );

    // double have size is 8 bytes
    bool vector_to_double( std::vector<unsigned char>* set_data
            , double* answer , unsigned int offset = 0 );

} // namespace convert

} // namespace convert

} // namespace zeabus

#endif // _ZEABUS_CONVERT_BYTES_HPP__
