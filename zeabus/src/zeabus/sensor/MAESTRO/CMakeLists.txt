add_library( MAESTROConnector SHARED 
    base_packet.cpp
}
target_link_libraries( IMUConnector 
    SynchronousPort 
    ${Boost_LIBRARIES}
)
