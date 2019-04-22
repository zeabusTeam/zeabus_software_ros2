add_library( ROSInterfaces SHARED 
    single_node.cpp    
)
ament_target_dependencies( ROSInterfaces rclcpp)
