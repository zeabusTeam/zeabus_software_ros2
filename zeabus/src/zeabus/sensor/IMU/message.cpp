// FILE         : message.cpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, APRIL 1

#include    <zeabus/sensor/IMU/message.hpp>

namespace zeabus
{
namespace sensor
{
namespace IMU
{

    void angular_velocity( std::vector<unsigned char>* data 
            , geometry_msgs::msg::Vector3* message , unsigned int offset )
    {
        // zeabus::conveert::bytes::vector_to_float( std::vector< unsgined char>* source)
        //      , float* result , unsigned int offset );
        float result; // float is 32 bit
        // because we don't ensure about size bit of data type
        (void)zeabus::convert::bytes::vector_to_float( data , &(result) , offset ); 
        message->x = result;  // this copy value don't copy bits to bits
        (void)zeabus::convert::bytes::vector_to_float( data , &(result) , offset + 4); 
        message->y = result; 
        (void)zeabus::convert::bytes::vector_to_float( data , &(result) , offset + 8); 
        message->z = result; 
    }

    void linear_acceleration( std::vector<unsigned char>* data 
            , geometry_msgs::msg::Vector3* message , unsigned int offset )
    {
        float result;
        // same situation of angular_velocity
        (void)zeabus::convert::bytes::vector_to_float( data , &(result) , offset ); 
        message->x = result;  // this copy value don't copy bits to bits
        (void)zeabus::convert::bytes::vector_to_float( data , &(result) , offset + 4); 
        message->y = result; 
        (void)zeabus::convert::bytes::vector_to_float( data , &(result) , offset + 8); 
        message->z = result; 
    }

    void orientation( std::vector<unsigned char>* data , geometry_msgs::msg::Quaternion* message 
            , unsigned int offset )
    {
        float result;
        (void)zeabus::convert::bytes::vector_to_float( data , &(result) , offset ); 
        message->w = result;  // this copy value don't copy bits to bits
        (void)zeabus::convert::bytes::vector_to_float( data , &(result) , offset + 4); 
        message->x = result;  // this copy value don't copy bits to bits
        (void)zeabus::convert::bytes::vector_to_float( data , &(result) , offset + 8); 
        message->y = result; 
        (void)zeabus::convert::bytes::vector_to_float( data , &(result) , offset + 12); 
        message->z = result;  
    }

} // namespace IMU

} // namespace sensor

} // namespace zeabus
