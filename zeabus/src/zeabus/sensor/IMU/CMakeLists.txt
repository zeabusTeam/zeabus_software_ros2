add_library( IMUConnector SHARED 
    packet.cpp
    connector.cpp
)
ament_target_dependencies( IMUConnector geometry_msgs )
target_link_libraries( IMUConnector SynchronousPort ${Boost_LIBRARIES})
