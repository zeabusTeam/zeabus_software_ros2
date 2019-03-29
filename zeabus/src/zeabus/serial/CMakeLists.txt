add_library( SynchronousPort SHARED 
        serial_port.cpp
        synchronous_port.cpp )
target_link_libraries( SynchronousPort ${Boost_LIBRARIES})
