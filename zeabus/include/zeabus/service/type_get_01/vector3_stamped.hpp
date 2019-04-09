// FILE         : vector3_stamped.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2018, APIRL 09

#include    <zeabus/service/type_get_01/base.hpp>

#include    "zeabus/srv/get_vector3_stamped.hpp"

#include    "geometry_msgs/msg/vector3_stamped.hpp"

#include    "rclcpp/rclcpp.hpp"

#include    <functional>

#include    <iostream>

#include    <memory> 

#ifdef _PRINT_SERVICE_CALL_
#include    <zeabus/escape_code.hpp>
#endif

#ifndef _ZEABUS_SERVICE_TYPE_GET_01_VECTRO3_STAMPED_HPP__
#define _ZEABUS_SERVICE_TYPE_GET_01_VECTRO3_STAMPED_HPP__

namespace zeabus
{
namespace service
{
namespace type_get_01
{

    class Vector3Stamped : public
            Base< zeabus::srv::GetVector3Stamped , zeabus::srv::GetVector3Stamped::Request
                    , zeabus::srv::GetVector3Stamped::Response 
                    , geometry_msgs::msg::Vector3Stamped >
    {
        public:
            Vector3Stamped( rclcpp::Node::SharedPtr* node );

            void callback( const std::shared_ptr< rmw_request_id_t > request_header 
                    , const std::shared_ptr< zeabus::srv::GetVector3Stamped::Request > request
                    , const std::shared_ptr< zeabus::srv::GetVector3Stamped::Response > 
                            response );

    }; // class TwistStamped 

} // namespace type_get_01

} // namespace service

} // namespace zeabus

#endif // _ZEABUS_SERVICE_TYPE_GET_01_VECTRO3_STAMPED_HPP__
