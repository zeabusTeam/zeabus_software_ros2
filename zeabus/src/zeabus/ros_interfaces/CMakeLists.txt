add_library( ROSInterfaces 
    single_node.cpp    
)
ament_target_dependencies( ROSInterfaces rclcpp)
set_target_properties( ROSInterfaces PROPERTIES COMPILE_FLAGS "-lthread -mt")
