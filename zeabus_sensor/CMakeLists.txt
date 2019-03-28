cmake_minimum_required(VERSION 3.5)
project(zeabus_sensor)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(zeabus_serial REQUIRED) # this we make we must to compile zeabus_serial first
find_package(rclcpp REQUIRED)

find_library( SynchroPortLib PATHS ${zeabus_serial_LIBRARIES})
set( zeabus_serial_headers ${zeabus_serial_INCLUDE_DIRS})
set( zeabus_serial_libraries ${zeabus_serial_LIBRARIES})
set( zeabus_serial_library_synchro_port $<zeabus_serial_LIBRARIES:SynchroPortLib>)

configure_file(
    "${PROJECT_SOURCE_DIR}/zeabus_sensor_path.hpp.in"
    "${PROJECT_BINARY_DIR}/zeabus_sensor_path.hpp"
)

include_directories( include
    ${zeabus_serial_headers} 
)

add_library( IMULib SHARED
    src/IMU/packet.cpp
    src/IMU/connector.cpp
)
target_link_libraries( IMULib ${zeabus_serial_LIBRARIES} )
ament_target_dependencies( IMULib zeabus_serial )

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

install( TARGETS)

ament_package()
