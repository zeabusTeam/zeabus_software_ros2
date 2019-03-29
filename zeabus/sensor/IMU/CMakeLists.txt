set( zeabus_sensor_IMU_source
    src/connector.cpp
    src/packet.cpp
)

add_library( zeabus_sensor_IMU_lib SHARED ${zeabus_sensor_IMU_source} )
target_link_libraries( zeabus_sensor_IMU_lib ${Boost_LIBRARIES} zeabus_serial_lib)

install( TARGETS zeabus_sensor_IMU_lib DESTINATION bin )
install( DIRECTORY "header/" DESTINATION include/zeabus/sensor/IMU)
ament_export_libraries( zeabus_sensor_IMU_lib )
