// FILE         : twist_stamped.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 08

#include    <zeabus/service/type_get_01/vector3_stamped.hpp>

namespace zeabus
{

namespace service
{

namespace type_get_01
{

    Vector3Stamped::Vector3Stamped( rclcpp::Node::SharedPtr node ) : Base( node )
    {
        this->function_pointer = std::bind( 
                &zeabus::service::type_get_01::Vector3Stamped::callback
                , this , std::placeholders::_1 , std::placeholders::_2
                , std::placeholders::_3 );
    } // Init function of class TwistStamped

    void Vector3Stamped::callback( const std::shared_ptr< rmw_request_id_t > request_header 
        , const std::shared_ptr< zeabus::srv::GetVector3Stamped::Request > request 
        , const std::shared_ptr< zeabus::srv::GetVector3Stamped::Response > response )
    {
#ifdef _PRINT_SERVICE_CALL_
        std::cout   << zeabus::escape_code::normal_red
                    << "Vector3Stamped::callack called\n" << zeabus::escape_code::normal_white;
#endif // _PRINT_SERVICE_CALL_
        (response->header).stamp = rclcpp::Time();
        response->data = *( this->data_pointer );
    } // function callback


} // namespace type_get_01

} // namespace service

} // namespace zeabus
