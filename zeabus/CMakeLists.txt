cmake_minimum_required( VERSION 3.5 )
project( zeabus )

find_package( ament_cmake REQUIRED ) # For use tool buil source code or package
find_package( Boost REQUIRED COMPONENTS ) # For use Boost library
find_package( geometry_msgs REQUIRED )
find_package( sensor_msgs REQUIRED )
find_package( std_msgs REQUIRED )

find_package( rosidl_default_generators REQUIRED ) # For build message? service and action

set( zeabus_source_path "${PROJECT_SOURCE_DIR}/src")
set( zeabus_include_path "${PROJECT_SOURCE_DIR}/include")

include_directories( 
    "${zeabus_include_path}" 
    "${Boost_INCLUDE_DIR}"
    "${PROJECT_BINARY_DIR}"
)

ament_export_include_directories( "${zeabus_include_path}" )

rosidl_generate_interfaces( ${PROJECT_NAME}
    "srv/GetSensorImu.srv"
    DEPENDENCIES std_msgs sensor_msgs geometry_msgs
)

ament_export_dependencies( rosidl_default_runtime ) # add went want to build service file

add_subdirectory( src )

set( SHARED_LIBS 
    SynchronousPort 
    IMUConnector
)

set( STATIC_LIBS
    Convert    
)


ament_export_libraries( ${STATIC_LIBS} )
ament_export_libraries( ${SHARED_LIBS} )

install( DIRECTORY "${PROJECT_SOURCE_DIR}/include/" DESTINATION include )

install( TARGETS ${STATIC_LIBS}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install( TARGETS ${SHARED_LIBS}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

ament_package()
