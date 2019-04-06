add_library( GetType01 STATIC
   sensor_imu.cpp
)
ament_target_dependencies( GetType01 
    rclcpp 
    sensor_msgs 
)

foreach( typesupport_impl ${typesupport_impls})
    rosidl_target_interfaces( GetType01 ${PROJECT_NAME} ${typesupport_impl} )
endforeach()
