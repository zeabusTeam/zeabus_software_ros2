add_library( General SHARED 
    escape_code.cpp
)

add_subdirectory( serial )

add_subdirectory( convert )

add_subdirectory( sensor )

add_subdirectory( service )
