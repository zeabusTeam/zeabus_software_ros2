// FILE         : sensor_imu.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019 , APIRL 04

#include    <zeabus/service/type_get_01/sensor_imu.hpp>

namespace zeabus
{
namespace service
{
namespace type_get_01
{

    SensorImu::SensorImu( rclcpp::Node::SharedPtr* node ) : Base( node )
    {
        this->function_pointer = std::bind( &zeabus::service::type_get_01::SensorImu::callback 
                , this , std::placeholders::_1 , std::placeholders::_2 
                , std::placeholders::_3 );
    } // init function of class SensorImu 

    void SensorImu::callback( const std::shared_ptr< rmw_request_id_t > request_header 
            , const std::shared_ptr< zeabus::srv::GetSensorImu::Request > request 
            , const std::shared_ptr< zeabus::srv::GetSensorImu::Response > response )
    {
        response->data = *(this->data_pointer);
    } // function SensorImu::callback

} // namespace type_get_01

} // namespace service

} // namespace zeabus
