add_library( General SHARED 
    escape_code.cpp
)

add_subdirectory( ros_interfaces )

add_subdirectory( math )

add_subdirectory( serial )

add_subdirectory( convert )

add_subdirectory( sensor )

add_subdirectory( service )
