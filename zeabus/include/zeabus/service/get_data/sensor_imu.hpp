// FILE         : sensor_imu.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019 , APRIL 18

// This file is service node for send data about imu
//  message is sensor_msg/msg/Imu
//  Follow structure in example_code of ros2 minimal_subscriber package 
//      member_function.cpp file

#include    "rclcpp/rclcpp.hpp"

#include    <iostream>

#include    "sensor_msgs/msg/imu.hpp"

#include    "zeabus/srv/get_sensor_imu.hpp"

#include    <memory>

#include    <functional> // include for std::bind

#include    <zeabus/escape_code.hpp>

#include    <zeabus/service/get_data/base_class.hpp>

#define _DECLARE_CALL_FUNCTION_ // use this macro when you want to know when function called

#ifndef _ZEABUS_SERVICE_GET_DATA_SENSOR_IMU_HPP__
#define _ZEABUS_SERVICE_GET_DATA_SENSOR_IMU_HPP__

namespace zeabus
{
namespace service
{
namespace get_data
{
    class SensorImu : public rclcpp::Node
    {
        public:
            SensorImu( std::string node_name ); // this function will init node together

            void regis_data( sensor_msgs::msg::Imu* pointer_data );

            void start_service( std::string topic_name );

            rclcpp::Service< zeabus::srv::GetSensorImu >::SharedPtr service_variable;

            void callback( 
                    const std::shared_ptr< rmw_request_id_t > request_header 
                    , const std::shared_ptr< zeabus::srv::GetSensorImu::Request > request
                    , const std::shared_ptr< zeabus::srv::GetSensorImu::Response > response );
        private:
            sensor_msgs::msg::Imu* pointer_data;

    }; // class SensorImu 

    class SensorImuDerived : public zeabus::service::get_data::BaseClass< sensor_msgs::msg::Imu >
    {
        public:
            SensorImuDerived::SensorImuDerived( std::string node_name );
            
            bool setup_service( std::string topic_name ) = 0 ;

            void callback( 
                    const std::shared_ptr< rmw_request_id_t > request_header 
                    , const std::shared_ptr< zeabus::srv::GetSensorImu::Request > request
                    , const std::shared_ptr< zeabus::srv::GetSensorImu::Response > response );

        private:
            rclcpp::Service zeabus::srv::GetSensorImu >::SharedPtr pointer_service;
    }; // class SensorImuDerived

} // namespace get_data

} // namespace service

} // namespace zeabus

#endif
