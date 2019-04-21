cmake_minimum_required( VERSION 3.5 )
project( zeabus )

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package( ament_cmake REQUIRED ) # For use tool buil source code or package
find_package( Boost REQUIRED COMPONENTS ) # For use Boost library
find_package( geometry_msgs REQUIRED )
find_package( sensor_msgs REQUIRED )
find_package( std_msgs REQUIRED )
find_package( rclcpp REQUIRED )
find_package( rosidl_default_generators REQUIRED ) # For build message? service and action

get_default_rmw_implementation( rmw_implementation ) # use after find package rclcpp
find_package( "${rmw_implementation}" REQUIRED ) # use after get default becuase wnat variable

set( zeabus_source_path "${PROJECT_SOURCE_DIR}/src")
set( zeabus_include_path "${PROJECT_SOURCE_DIR}/include")

rosidl_generate_interfaces( ${PROJECT_NAME}
    "srv/GetSensorImu.srv"
    "srv/GetTwistStamped.srv"
    "srv/GetVector3Stamped.srv"
    DEPENDENCIES std_msgs sensor_msgs geometry_msgs
)

ament_export_dependencies( rosidl_default_runtime ) # add went want to build service file

include_directories( 
    "${zeabus_include_path}" 
    "${Boost_INCLUDE_DIR}"
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_BINARY_DIR}/rosidl_generator_cpp/"
)

ament_export_include_directories( "${zeabus_include_path}" )

get_rmw_typesupport( typesupport_impls "${rmw_implementation}" LANGUAGE "cpp")

add_subdirectory( src )
    

set( SHARED_LIBS 
    SynchronousPort
    DVLConnector 
    IMUConnector
    MAESTROConnector
    GetData
)

set( STATIC_LIBS
    Convert   
    Math
    ROSInterfaces 
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
