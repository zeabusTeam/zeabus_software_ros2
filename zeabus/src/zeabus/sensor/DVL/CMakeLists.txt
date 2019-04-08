add_library( DVLConnector SHARED 
    connector.cpp
)
target_link_libraries( DVLConnector 
    SynchronousPort 
    ${Boost_LIBRARIES}
)
