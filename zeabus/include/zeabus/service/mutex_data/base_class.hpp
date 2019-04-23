// FILE         : base_class.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 22

#include    <iostream>

#include    "zeabus/ros_interface/single_node.hpp"

#include    "rclcpp/rclcpp.hpp"

#include    <memory> // std::shared_ptr

#include    <mutex> // use mutex

#ifndef _ZEABUS_SERVICE_MUTEX_DATA_BASE_CLASS_HPP__
#define _ZEABUS_SERVICE_MUTEX_DATA_BASE_CLASS_HPP__

namespace zeabus
{

namespace service
{

namespace mutex_data
{

    template< class message_type >
    class BaseClass : public zeabus::ros_interfaces::SingleNode
    {

        private:
            bool already_regis_data; // use have send pointer data?
            bool already_regis_mutex; // use have send std::shared_ptr<mutex>?

        protected:
            message_type* pointer_data;
            std::shared_ptr< std::mutex > pointer_mutex;

        public:
            BaseClass( std::string node_name ) : zeabus::ros_interfaces::SingleNode( node_name )
            {
                already_regis_data = false;
                already_regis_mutex = false;
            } // function constructor

            bool check_setup()
            {
                return already_regis_data && already_regis_mutex;
            } // function already_setup

            void regis_data( message_type* pointer_data )
            {
                this->pointer_data = pointer_data;
                this->already_regis_data = true;
            }

            void regis_mutex( std::shared_ptr< std::mutex > pointer_mutex )
            {
                this->pointer_mutex = pointer_mutex;
                this->already_regis_mutex = true;
            }

    }; // class BaseClass

} // namespace mutex_data

} // namespace service

} // namespace zeabus

#endif // _ZEABUS_SERVICE_MUTEX_DATA_BASE_CLASS_HPP__
