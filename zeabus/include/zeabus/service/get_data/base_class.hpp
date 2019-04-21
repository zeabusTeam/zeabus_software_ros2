// FILE         : base_class.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 20

// This file is manage connection about use with fundamental of service type get_data
// In callback we can't to use template to function callback 
// That make us can do only this

#include    <iostream>

#include    "zeabus/ros_interfaces/single_node.hpp"

#include    "rclcpp/rclcpp.hpp"

#ifndef _ZEABUS_SERVICE_GET_DATA_BASE_CLASS_HPP__
#define _ZEABUS_SERVICE_GET_DATA_BASE_CLASS_HPP__

namespace zeabus
{

namespace service
{

namespace get_data
{

    template< class message_type >
    class BaseClass : public zeabus::ros_interfaces::SingleNode 
    {

        private:
            bool already_regis;

        protected:
            messae_type* pointer_data; // for collect data

        // end part of  protected
        public:
            BaseClass( std::string node_name ) : zeabus::ros_interfaces::SingleNode( node_name )
            {
                already_regis = false;
            } // function constuctor

            void regis_message( message_type* pointer_data )
            {
                this->pointer_data = pointer_data;
                already_regis = true;
            } // function regis_message

            bool check_register()
            {
                return this->already_regis;
            } // function check_register        

            // Follow MISRA C++ 
            virtual bool setup_service( std::string topic_name ) = 0 ;


    } // class BaseClass

} // namespace get_data

} // namespace service

} // namespace zeabus

#endif // definition _ZEABUS_SERVICE_GET_DATA_BASE_CLASS_HPP__
