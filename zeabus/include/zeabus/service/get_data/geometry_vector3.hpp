// FILE         : geometry_vector3.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 23

// This file is service node for send data about geomety_msgs/msg/vector3*
// But I will create only geometry_msgs/msg/vector3_stamped becuse we use only that

#include    "rclcpp/rclcpp.hpp"

#include    <iostream>

#include    "geometry_msgs/msg/vector3_stamped.hpp"

#include    "zeabus/srv/get_vector3_stamped.hpp"

#include    <memory> // std::shared_ptr

#include    <functional> // std::bind

#include    <zeabus/escape_code.hpp>

#include    <zeabus/service/get_data/base_class.hpp>

#define _DECLARE_CALLBACK_FUNCTION_

#ifndef _ZEABUS_SERVICE_GET_DATA_GEOMETRY_VECTOR3_HPP__
#define _ZEABUS_SERVICE_GET_DATA_GEOMETRY_VECTOR3_HPP__

namespace zeabus
{

namespace service
{

namespace get_data
{

    class GeometryVector3Stamped : 
            public zeabus::service::get_data::BaseClass< geometry_msgs::msg::Vector3Stamped >
    {
        GeometryVector3Stamped( std::string node_name );
        
        bool setup_service( std::string topic_name );

        void callback(
                const std::shared_ptr< rmw_request_id_t > request_header
                , const std::shared_ptr< zeabus::srv::GetVector3Stamped::Request > request
                , const std::shared_ptr< zeabus::srv::GetVector3Stamped::Response > response
                );

        private:
            rclcpp::Service< zeabus::srv::GetVector3Stamped >::SharedPtr pointer_service;
    }; // class GetVector3Stamped

} // namespace get_data

} // namespace service

} // namespace zeabus

#endif // _ZEABUS_SERVICE_GET_DATA_GEOMETRY_VECTOR3_HPP__
