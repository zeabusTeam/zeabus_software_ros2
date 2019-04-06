// FILE         : one_byte.hpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, APRIL 1

#include    <zeabus/convert/bytes.hpp>

#include    "geometry_msgs/msg/vector3.hpp"
#include    "geometry_msgs/msg/quaternion.hpp"

#include    <iostream>

#include    <vector>

// Purpose of this file will manage about data from IMU (Inertial Measurement Unit)
// In ros2 operating have 
//      geometry_msgs/Quaternion orientation
//      geometry_msgs/Vector3 angular_velocity
//      geometry_msgs/Vector3 linear_acceleration
// This library have make for data packet from LORD MICROSTRAIN 3dm-gx5-45 only
// one byte that mean 1 member have size is 8 bits

#ifndef _ZEABUS_CONVERT_VECTOR_ONE_BYTE_HPP
#define _ZEABUS_CONVERT_VECTOR_ONE_BYTE_HPP

namespace zeabus
{

namespace convert
{

namespace vector
{

namespace one_byte
{
// for use this function we ensure you will use with packet form of LORD MICROSTRAIN
// That make we don't care about error of size
    void vector3( std::vector< unsigned char >* data 
            , geometry_msgs::msg::Vector3* message , unsigned int offset );

    void quaternion( std::vector< unsigned char >* data 
            , geometry_msgs::msg::Quaternion* message , unsigned int offset );

// How to know about offset? please send postion start that data or +1 position of Descriptor
    
} // namespace one_byte

} // namespace IMU

} // namespace sensor

} // namespace zeabus 


#endif // _ZEABUS_SENSOR_IMU_MESSAGE_HPP__
