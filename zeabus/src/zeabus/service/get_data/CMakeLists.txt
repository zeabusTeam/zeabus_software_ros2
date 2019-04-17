add_library( GetData STATIC
    sensor_imu.cpp
) 
target_link_libraries( GetData
    rclcpp
    sensor_msgs
) 

# this make me can use libary have exported by own package in one time
foreach( typesupport_impl ${typesupport_impls} )
    rosidl_target_interface( GetData ${PROJECT_NAME} ${typesupport_impl})
endforeach
