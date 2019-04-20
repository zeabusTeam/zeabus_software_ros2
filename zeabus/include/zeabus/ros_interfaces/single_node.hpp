// FILE         : single_node.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 19

// Reference about thread
//      ref1    : https://en.cppreference.com/w/cpp/thread
//      ref2    : http://www.cplusplus.com/reference/thread/thread/ <esay to read>
//      ref3    : http://www.cplusplus.com/reference/thread/thread/operator=/ <assign thread>

// Reference about class
//      ref     : https://en.cppreference.com/w/cpp/language/class
//              study about template type

// Macro Detail
//      _PRINT_THREAD_PROCESS_ will print about status thread spin_node & spin_some_node

#include    <thread> // for spilt thread to spind in ros system

#include    <iostream> // standard library for cpp language

#include    "rclcpp/rclcpp.hpp" // use Node class and rclcpp::ok() function

#include    <memory> // use std::shared_ptr and std::make_shardedptr?
                    // use enable_shared_from_this< class > object

#ifndef _ZEABUS_ROS_INTERFACES_SINGLE_NODE_HPP__
#define _ZEABUS_ROS_INTERFACES_SINGLE_NODE_HPP__

namespace zeabus
{

namespace ros_interfaces
{

    class SingleNode : 
            public rclcpp::Node 
    {
        private:
            std::thread my_thread; // empty thread will use swap to fill thread
            void spin_node(); // this function will call when wants to spin thread
            void spin_some_node();
        // end part of private privacy. Default is private. 
        protected:
            SingleNode( std::string node_name );
            bool status_my_thread; // true when now spinning

        public:
            bool spin(); // use to spin this node
            bool spin_some(); // use to spin_some this node
            bool current_status(); //  return status_my_thread
            
        // end part of protected privacy

    }; // class SingleNode

} // namespace ros_interface

} // namespace zeabus

#endif
