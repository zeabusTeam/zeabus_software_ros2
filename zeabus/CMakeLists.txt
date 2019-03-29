cmake_minimum_required( VERSION 3.5 )
project( zeabus )

find_package( ament_cmake REQUIRED )
find_package( Boost REQUIRED COMPONENTS system)

set( include_lib
    "${PROJECT_SOURCE_DIR}/serial/header"
    "${PROJECT_SOURCE_DIR}/sensor/IMU/header"
    "${PROJECT_SOURCE_DIR}/serial/src"
    "${PROJECT_SOURCE_DIR}/sensor/IMU/src"
    
)

include_directories( ${include_lib} )

add_subdirectory( serial )
set( EXTRA_LIBS ${EXTRA_LIBS} zeabus_serial_lib)

add_subdirectory( sensor )
set( EXTRA_LIBS ${EXTRA_LIBS} zeabus_sensor_IMU_lib)

ament_export_include_directories( ${include_lib} "${PROJECT_SOURCE_DIR}")

ament_package()
