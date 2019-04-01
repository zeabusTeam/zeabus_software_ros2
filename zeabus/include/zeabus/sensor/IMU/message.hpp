// FILE         : message.hpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, APRIL 1

#include    <zeabus/convert/bytes.hpp>

#include    <zeabus/sensor/IMU/LORD_IMU_COMMUNICATION.hpp>

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

#ifdef _ZEABUS_SENSOR_IMU_MESSAGE_HPP__
#define _ZEABUS_SENSOR_IMU_MESSAGE_HPP__

namespace zeabus
{

namespace sensor
{

namespace IMU
{
// for use this function we ensure you will use with packet form of LORD MICROSTRAIN
// That make we don't care about error of size
    void angular_velocity( std::vector< unsigned char > data , geometry_msgs::Vector3* message
            , unsigned int offset );

    void linear_acceleration( std::vector< unsigned char > data 
            , geometry_msgs::Vector3* message , unsigned int offset );

    void orientation( std::vector< unsigned char > data , geometry_msgs::Quaternion message 
            , unsigned int offset );

// How to know about offset? please send postion start that data or +1 position of Descriptor
    

} // namespace IMU

} // namespace sensor

} // namespace zeabus 


#endif // _ZEABUS_SENSOR_IMU_MESSAGE_HPP__
