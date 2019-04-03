add_library( IMUConnector SHARED 
    packet.cpp
    connector.cpp
    message.cpp
)
ament_target_dependencies( IMUConnector Convert geometry_msgs )
target_link_libraries( IMUConnector SynchronousPort ${Boost_LIBRARIES})
