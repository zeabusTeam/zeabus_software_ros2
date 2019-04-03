// FILE         : one_byte.cpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, APRIL 1

#include    <zeabus/convert/vector.hpp>

namespace zeabus
{
namespace convert
{
namespace vector
{
namespace one_byte
{

    void vector3( std::vector<unsigned char>* data 
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

    void quaternion( std::vector<unsigned char>* data , geometry_msgs::msg::Quaternion* message 
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

} // namespace one_byte

} // namespace vector

} // namespace convert

} // namespace zeabus
