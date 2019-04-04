// FILE         : type_get.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019 , APRIL 03

#include    <memory> // use std::shared_ptr followe example code

#include    "rclcpp/rclcpp.hpp"

#include    <iostream>

// MACRO DETAIL FOR DEBUG
//      _SERVICE_CALL_

// warning this template using for service type get formal of srv
//      bool data
//      ---
//      std_msgs/Header header
//      answer_data
// by using template

#ifndef _ZEABUS_SERVICE_GET_TYPE_HPP__
#define _ZEABUS_SERVICE_GET_TYPE_HPP__

namespace zeabus
{

namespace service
{

    template< typename service_type , class data_type>
    class type_get
    {
        public:
            // this function for get node to create service
            type_get( rclcpp::Node::SharedPtr node )
            {
                this->node = node;
            } // function init class

            // I don't know how to set only part of namespace that make me decide to use template
            void handle_service(
                    const std::shared_ptr< rmw_request_id_t > request_header 
                    , const std::shared_ptr< service_type::Request > request 
                    , const std::shared_ptr< service_type::Response > response )
            {
#ifdef _SERVICE_CALL_
                std::cout << "Call service " << this->service_name << std::endl;
#endif // _SERVICE_CALL_
                response->data = *(this->data_pointer);
            } // function handle service

            // you will register pointer of data you want to response service
            auto create_service( data_type* data_pointer , std::string topic_name )
            {
                this->service_name = topic_name;
                this->data_pointer = data_pointer;
                return this->node->create_service< service_type >( topic_name 
                        , this->handle_service );
                    // , zeabus::service::type_get< service_type , data_type >::handle_service 
                    // , this );
            } // function create_service 

        protected:
            rclcpp::Node::SharedPtr node;
            data_type* data_pointer;
            std::string service_name;
                
            
    }; // class type_get

} // namespace service

} // namespace zeabus

#endif // _ZEABUS_SERVICE_GET_TYPE_HPP__
