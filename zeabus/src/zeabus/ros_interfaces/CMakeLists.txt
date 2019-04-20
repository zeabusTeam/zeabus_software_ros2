add_library( ROSInterfaces STATIC
    single_node.cpp    
)
ament_target_dependencies( ROSInterfaces rclcpp)
