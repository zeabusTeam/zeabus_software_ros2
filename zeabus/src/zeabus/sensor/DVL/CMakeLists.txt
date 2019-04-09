add_library( DVLConnector SHARED 
    connector.cpp
    decode_string.cpp
)
target_link_libraries( DVLConnector 
    SynchronousPort 
    Convert
    ${Boost_LIBRARIES}
)
