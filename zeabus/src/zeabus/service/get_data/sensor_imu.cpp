// FILE         : sensor_imu.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 18

#include    <zeabus/service/get_data/sensor_imu.hpp>

// MACRO DETAIL
//  _DECLARE_CALL_FUNCTION_

namespace zeabus
{

namespace service
{

namespace get_data
{

    SensorImu::SensorImu( std::string node_name ) : rclcpp::Node( node_name )
    {
#ifdef _DECLARE_CALL_FUNCTION_
        std::cout   << zeabus::escape_code::normal_green 
                    << "SensorImu init class\n" << zeabus::escape_code::normal_white; 
#endif 
    } // function init SensorImu

    void SensorImu::start_service( std::string topic_name )
    {
#ifdef _DECLARE_CALL_FUNCTION_
        std::cout   << zeabus::escape_code::normal_green
                    << "SensorImu start_service\n" << zeabus::escape_code::normal_white;
#endif
        this->service_variable = this->create_service< zeabus::srv::GetSensorImu >( topic_name 
                , std::bind( &SensorImu::callback , this , std::placeholders::_1
                        , std::placeholders::_2 , std::placeholders::_3 
                ) // std::bind function 
        ); // declarre service_variable
    } // function start_service

    void SensorImu::regis_data( sensor_msgs::msg::Imu* pointer_data )
    {
#ifdef _DECLARE_CALL_FUNCTION_
        std::cout   << zeabus::escape_code::normal_green
                    << "SensorImu regis data function\n" << zeabus::escape_code::normal_white;
#endif     
        this->pointer_data = pointer_data;
    } // function regis_data

    void SensorImu::callback(
            const std::shared_ptr< rmw_request_id_t > request_header  
            , const std::shared_ptr< zeabus::srv::GetSensorImu::Request > request 
            , const std::shared_ptr< zeabus::srv::GetSensorImu::Response > response )
    {
        (void)request_header;
#ifdef _DECLARE_CALL_FUNCTION_
        std::cout   << zeabus::escape_code::bold_red
                    << "SensorImu callback called\n" << zeabus::escape_code::normal_white;
#endif
        (response->header).stamp = rclcpp::Time();
        response->data = *(this->pointer_data);
    } // function callback

} // namespace get_data

} // namespace service

} // namespace zeabus
