// FILE         : twist_stamped.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 08

#include    <zeabus/service/type_get_01/base.hpp> // get base class of service 
 
#include    "zeabus/srv/get_twist_stamped.hpp" // get service structure in ros system

#include    "geometry_msgs/msg/imu.hpp"

#include    "rclcpp/rclcpp.hpp"

#include    <functional> // we want to make vaiable point to function

#include    <iostream>

#include    <memory>

namespace zeabus
{

namespace service
{

namespace type_get_01
{

    class TwistStamped : public
            Base< zeabus::srv::GetTwistStamped , zeabus::srv::GetTwistStamped::Request
                    , zeabus::srv::GetTwistStamped::Response , geometry_msgs::msg::TwistStamped >
    {
        public:
            TwistStamped( rclcpp::Node::SharedPtr* node );

            void callback( const std::shared_ptr< rmw_request_id_t > request_header 
                    , const std::shared_ptr< zeabus::srv::GetTwistStamped::Request > request
                    , const std::shared_ptr< zeabus::srv::GetTwistStamped::Response > response );

    }; // class TwistStamped 

} // namespace type_get_01

} // namespace service

} // namespace zeabus
