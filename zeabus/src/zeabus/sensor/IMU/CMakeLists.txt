add_library( IMUConnector SHARED 
    packet.cpp
    connector.cpp
)
target_link_libraries( IMUConnector 
    SynchronousPort 
    ${Boost_LIBRARIES}
)
