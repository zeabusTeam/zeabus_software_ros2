add_library( GetData SHARED
    sensor_imu.cpp
    geometry_vector3.cpp
) 
ament_target_dependencies( GetData rclcpp sensor_msgs ROSInterfaces geometry_msgs)

# this make me can use libary have exported by own package in one time
foreach( typesupport_impl ${typesupport_impls} )
    rosidl_target_interfaces( GetData ${PROJECT_NAME} ${typesupport_impl})
endforeach()
