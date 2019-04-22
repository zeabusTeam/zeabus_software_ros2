// FILE         : single_node.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 20

#include    <zeabus/ros_interfaces/single_node.hpp>

// MACRO DETAIL
// _PRINT_THREAD_PROCESS_ will print about before and after thread spin

namespace zeabus
{

namespace ros_interfaces
{

    SingleNode::SingleNode( std::string node_name ) : rclcpp::Node( node_name )
    {
        // false mean now we don't have to spin anymore
        this->status_my_thread = false;
    } // function constructor of SingleNode

    void SingleNode::spin_node()
    {
        this->status_my_thread = true;
        if( rclcpp::ok() )
        {   
            // In class of rclcpp::Node have derived from enable_shared_from_this
            //  ref of rclcpp::node = docs.ros2.org/crystal/api/rclcpp/node_8hpp_source.html
#ifdef _PRINT_THREAD_PROCESS_
            std::cout   << zeabus::escape_code::normal_margenta << "start spin of " 
                        << this->get_name() << zeabus::escape_code::bold_white << std::endl;
#endif
            rclcpp::spin();
#ifdef _PRINT_THREAD_PROCESS_
            std::cout   << zeabus::escape_code::normal_margenta << "end spin of " 
                        << this->get_name() << zeabus::escape_code::bold_white << std::endl;
#endif
        } // condition rclcpp ok
        this->status_my_thread = false;
    } // function spin_node

    // in return of this don't mean we already spin but mean we have spin 
    // but mean we have split thread to run or not
    bool SingleNode::spin()
    {
        bool result = false;
        if( ! (this->status_my_thread) )
        {
            if( rclcpp::ok() )
            {
                this->my_thread = std::thread( std::bind( 
                        &zeabus::ros_interfaces::SingleNode::spin_node 
                        , this 
                        ) // std::bind
                ); // assign my_thread
                result = true;
            } // check ros handle
        } // condition already have thread?
        return result;
    } // function spin

    bool SingleNode::current_status()
    {
        return this->status_my_thread;
    } // function current_status

} // namespace ros_interface

} // namespace zeabus
