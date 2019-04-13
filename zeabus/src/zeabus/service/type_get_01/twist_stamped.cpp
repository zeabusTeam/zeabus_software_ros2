// FILE         : twist_stamped.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 08

#include    <zeabus/service/type_get_01/twist_stamped.hpp>

namespace zeabus
{

namespace service
{

namespace type_get_01
{

    TwistStamped::TwistStamped( rclcpp::Node::SharedPtr node ) : Base( node )
    {
        this->function_pointer = std::bind( &zeabus::service::type_get_01::TwistStamped::callback
                , this , std::placeholders::_1 , std::placeholders::_2
                , std::placeholders::_3 );
    } // Init function of class TwistStamped

    void TwistStamped::callback( const std::shared_ptr< rmw_request_id_t > request_header 
        , const std::shared_ptr< zeabus::srv::GetTwistStamped::Request > request 
        , const std::shared_ptr< zeabus::srv::GetTwistStamped::Response > response )
    {
#ifdef _PRINT_SERVICE_CALL_
        std::cout   << zeabus::escape_code::normal_red
                    << "TwistStamped::callack called\n" << zeabus::escape_code::normal_white;
#endif // _PRINT_SERVICE_CALL_
        (response->header).stamp = rclcpp::Time();
        response->data = *( this->data_pointer );
    } // function callback


} // namespace type_get_01

} // namespace service

} // namespace zeabus
