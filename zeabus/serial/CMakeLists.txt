set( zeabus_serial_source
    src/serial_port.cpp
    src/synchronous_port.cpp
)

add_library( zeabus_serial_lib SHARED ${zeabus_serial_source} )
target_link_libraries( zeabus_serial_lib ${Boost_LIBRARIES})
ament_target_dependencies( zeabus_serial_lib Boost)

install( TARGETS zeabus_serial_lib DESTINATION bin )
install( DIRECTORY "header/" DESTINATION include/zeabus/serial)
ament_export_libraries( zeabus_serial_lib )
