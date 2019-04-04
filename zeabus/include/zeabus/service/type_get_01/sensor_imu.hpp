// FILE         : sensor_imu.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2018, APIRL 04

#include    <zeabus/service/type_get_01/base.hpp> // get base class of service 
 
#include    "zeabus/srv/get_sensor_imu.hpp" // get service structure in ros system

#include    "sensor_msgs/msg/Imu.hpp"

#include    "rclcpp/rclcpp.hpp"

#include    <iostream>

#include    <memory> 

#ifndef _ZEABUS_SERVICE_TYPE_GET_01_BASE_HPP__
#define _ZEABUS_SERVICE_TYPE_GET_01_BASE_HPP__

namespace zeabus
{
namespace service
{
namespace type_get_01
{

    class SensorImu : public Base< zeabus::srv::GetSensorImu , zeabus::srv::GetSensorImu::Reques
            , zeabus::srv::GetSensorImu::Response , sensor_msgs::msg::Imu >
    {
        public:
            SensorIMU( rclcpp::Node::sharedPtr node ) ;

            void callback( const std::shared_ptr< rmw_request_id_t > request_header 
                    , const std::shared_ptr< zeabus::srv::GetSensorImu::Request > request 
                    , const std::shared_ptr< zeabus::srv::GetSensorImu::Response > response );

    }; // class SensorIMU 

} // namespace type_get_01

} // namespace service

} // namespace zeabus

#endif // _ZEABUS_SERVICE_TYPE_GET_01_BASE_HPP__
