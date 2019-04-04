add_library( GetType01 STATIC
   sensor_imu.cpp
)
ament_target_dependencies( GetType01 rclcpp sensor_msgs )
