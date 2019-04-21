add_library( ROSInterfaces 
    single_node.cpp    
)
ament_target_dependencies( ROSInterfaces rclcpp)
target_compile_options( ROSInterfaces PRIVATE -pthread )
