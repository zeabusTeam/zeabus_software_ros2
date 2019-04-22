add_library( GetData SHARED
    sensor_imu.cpp
    sensor_imu_derived.cpp
) 
ament_target_dependencies( GetData rclcpp sensor_msgs ROSInterfaces)

# this make me can use libary have exported by own package in one time
foreach( typesupport_impl ${typesupport_impls} )
    rosidl_target_interfaces( GetData ${PROJECT_NAME} ${typesupport_impl})
endforeach()
