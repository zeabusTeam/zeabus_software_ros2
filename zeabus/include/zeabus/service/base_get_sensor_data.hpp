// FILE         : base_get_sensor_data.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 14

#include    <iostream> // standard library for C++ language

#include    <functional> // std::bind function for send to ros2 api

#include    <zeabus/escape_code.hpp>

#include    <memory>

#include    "rclcpp/rclcpp.hpp" // include library ros2

// ======> MACRO DETAIL
// ===> _PRINT_CALL_BACK_ // for print when callback function have been call


#ifndef _ZEABUS_SERVICE_BASE_GET_SENSOR_DATA_HPP__
#define _ZEABUS_SERVICE_BASE_GET_SENSOR_DATA_HPP__

namespace zeabus
{

namespace service
{

    template< class service_type , class request_type , class response_type , class data_type >
    class BaseGetSensorData : public rclcpp::Node
    {
        public : 
            BaseGetSensorData( std::string node_name , std::string topic_name = "" ) 
                    : Node( node_name )
            {
#ifdef _PRINT_CALL_BACK_
                this->node_name = node_name;
#endif
                this->topic_name = topic_name;
                this->pointer_data = nullptr;
            } // function init class BaseGetSensorData

            bool create_service( std::string topic_name = "" )
            {
                if( topic_name != "" )
                {
                    this->topic_name = topic_name;
                }
                bool result = true;
                if( this->pointer_data == nullptr )
                {   
                    std::cout   << zeabus::escape_code::normal_red 
                                << "please register before create service"
                                << " We want data_pointer\n" 
                                << zeabus::escape_code::normal_white;
                    result = false;
                } // if condition when you didn't register data pointter
                else
                { 
                    service = this->create_service< service_type >( this->topic_name , std::bind(
                            &zeabus::service::BaseGetSensorData::callback , this ,
                            std::placeholders::_1 , std::placeholders::_2 , std::placeholders::_3
                        ) // std::bind function by include <functional> 
                    ); // declare service
                } // else condition when you already register data pointer
                return result;
            } // function create_service

            void register_data( data_type* pointer_data )
            {
               this->pointer_data = pointer_data; 
            } // function pointer data

        private :
            void callback( const std::shared_ptr< rmw_request_id_t > request_header 
                    , const std::shared_ptr< request_type > request
                    , const std::shared_ptr< response_type > response )
            {
#ifdef _PRINT_CALL_BACK_
                std::cout   << zeabus::escape_code::normal_margenta << 
                            << " callback have been call\n" << zeabus::escape_code::normal_white;
#endif
                (response->header).stamp = rclcpp::Time();
                response->data = *(this->pointer_data);
            } // function callback

#ifdef _PRINT_CALL_BACK_
            std::string node_name;
#endif
            std::string topic_name;
            rclcpp::Service< service_type >::SharedPtr service;
            data_type* pointer_data;
    }; // class BaseGetSensorData

} // namespace service

} // namespace zeabus

#endif // _ZEABUS_SERVICE_BASE_GET_SENSOR_DATA_HPP__
