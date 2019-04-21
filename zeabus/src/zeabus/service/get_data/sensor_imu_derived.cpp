// FILE         : sensor_imu_derived.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 22

#include    <zeabus/service/get_data/sensor_imu.hpp>

// MACRO DETAIL
// _DECLARE_CALLBACK_FUNCTION_ // Print detail when callback called

namespace zeabus
{

namespace service
{

namespace get_data
{

    SensorImuDerived::SensorImuDerived( std::string node_name ) : BaseClass( node_name )
    {
       ; // Don't have anything
    } // constructor function of class SensorImuDerived

    bool SensorImuDerived::setup_service( std::string topic_name )
    {
        this->pointer_service = this->create_service< zeabus::srv::GetSensorImu >( topic_name 
                , std::bind( &SensorImuDerived::callback , this , std::placeholders::_1
                        , std::placeholders::_2 , std::placeholders::_3 
                ) // std::bind function 
        ); // declare pointer_service
        return this->check_register(); 
        // we want to warning you don't for get to register message pointer to send data
    } // function setup_service

    void SensorImuDerived::callback(
            const std::shared_ptr< rmw_request_id_t > request_header
            , const std::shared_ptr< zeabus::srv::GetSensorImu::Request > request
            , const std::shared_ptr< zeabus::srv::GetSensorImu::Response > response )
    {
#ifdef _DECLARE_CALLBACK_FUNCTION_
        std::cout   << "Callback of " << zeabus::escape_code::normal_red << this->get_name() 
                    << " have been call\n" << zeabus::escape_code::normal_while; 
#endif // definition _DECLARE_CALLBACK_FUNCTION_
        (void)request_header;
        (response->header).stamp = rclcpp::Time();
        response->data = *(this->pointer_data);
    }

} // namespace get_data

} // namespace service

} // namespace zeabus
