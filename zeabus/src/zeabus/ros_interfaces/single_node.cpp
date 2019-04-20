// FILE         : single_node.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 20

#include    <zeabus/ros_interfaces/single_node.hpp>

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
            rclcpp::spin( this->shared_from_this() );
        } // condition rclcpp ok
        this->status_my_thread = false;
    } // function spin_node

    void SingleNode::spin_some_node()
    {
        this->status_my_thread = true;
        if( rclcpp::ok() )
        {
            rclcpp::spin_some( this->shared_from_this() ); // derived by rclcpp::Node
        } // condtion rclcpp ok
        this->status_my_thread = false;
    } // function spin_some_node

    // in return of this don't mean we already spin but mean we have spin 
    // but mean we have split thread to run or not
    bool SingleNode::spin()
    {
        bool result = false;
        if( ! (this->status_my_thread) )
        {
            if( rclcpp::ok() )
            {
                this->my_thread = std::thread( 
                        &zeabus::ros_interfaces::SingleNode::spin_node 
                        , this );
                result = true;
            } // check ros handle
        } // condition already have thread?
        return result;
    } // function spin

    bool SingleNode::spin_some()
    {
        bool result = false;
        if( ! ( this->status_my_thread ) )
        {
            if( rclcpp::ok() )
            {
                this->my_thread = std::thread( 
                        &zeabus::ros_interfaces::SingleNode::spin_some_node
                        , this );
                result = true;
            } // check ros handle
        } // condition already have thread?
        return result;
    } // function spin_some

    bool SingleNode::current_status()
    {
        return this->status_my_thread;
    } // function current_status

} // namespace ros_interface

} // namespace zeabus
