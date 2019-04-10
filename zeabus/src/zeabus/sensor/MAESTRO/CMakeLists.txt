add_library( MAESTROConnector SHARED 
    base_packet.cpp
    pololu_packet.cpp
)
target_link_libraries( MAESTROConnector 
    SynchronousPort 
    ${Boost_LIBRARIES}
)
