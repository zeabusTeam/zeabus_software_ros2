// FILE         : geometry_vector3.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 23

#include    <zeabus/service/get_data/geometry_vector3.hpp>

// MACRO DETAIL
// _DECLARE_CALLBACK_FUNCTION_ // Print detail when callback called

namespace zeabus
{

namespace service
{

namespace get_data
{

    GeometryVector3Stamped::GeometryVector3Stamped( std::string node_name ) : 
            BaseClass( node_name)
    {
        ; // Don't do anything
    } // function construtor

    bool GeometryVector3Stamped::setup_service( std::string topic_name )
    {
        this->pointer_service = this->create_service< zeabus::srv::GetVector3Stamped >( 
                topic_name , std::bind( &GeometryVector3Stamped::callback , this 
                , std::placeholders::_1 , std::placeholders::_2 , std::placeholders::_3 
            ) // std::bind function 
        ); // declare pointer_service
    } // function setup_service

    void GeometryVector3Stamped::callback(
        const std::shared_ptr< rmw_request_id_t > request_header
        , const std::shared_ptr< zeabus::srv::GetVector3Stamped::Request > request 
        , const std::shared_ptr< zeabus::srv::GetVector3Stamped::Response > response )
    {
#ifdef _DECLARE_CALLBACK_FUNCTION_
        std::cout   << "Callback of " << zeabus::escape_code::normal_red << this->get_name() 
                    << " have been call\n" << zeabus::escape_code::bold_white; 
#endif // definition _DECLARE_CALLBACK_FUNCTION_
        (void)request_header;
        (response->header).stamp = rclcpp::Time();
        response->data = *(this->pointer_data);
    } // function callback 

} // namespace get_data

} // namespace service

} // namespace zeabus
