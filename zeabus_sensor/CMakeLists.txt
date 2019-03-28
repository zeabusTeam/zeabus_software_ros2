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
find_package(zeabus_serial REQUIRED)
find_package(rclcpp REQUIRED)

set( zeabus_serial_dir ${zeabus_serial_DIR})
set( zeabus_serial_headers ${zeabus_serial_INCLUDE_DIRS})
set( zeabus_serial_libraries ${zeabus_serial_LIBRARIES})

configure_file(
    "${PROJECT_SOURCE_DIR}/zeabus_sensor_path.hpp.in"
    "${PROJECT_BINARY_DIR}/zeabus_sensor_path.hpp"
)

include_directories( include
    ${zeabus_serial_INCLUDE_DIRS} 
)

add_library( IMULib SHARED
    src/IMU/packet.cpp
    src/IMU/connector.cpp
)
target_link_libraries( IMULib ${zeabus_serial_LIBRARIES} ${Boost_LIBRARIES})
ament_target_dependencies( IMULib zeabus_serial Boost)


install(
    FILES   ${PROJECT_SOURCE_DIR}/src/IMU/connector.hpp
            ${PROJECT_SOURCE_DIR}/src/IMU/packet.hpp
    DESTINATION include/zeabus/sensor/IMU
)

install( TARGETS IMULib DESTINATION bin )
install( TARGETS IMULib LIBRARY DESTINATION lib )

add_executable( imu_node src/IMU/node.cpp )
target_link_libraries( imu_node ${zeabus_serial_LIBRARIES} IMULib)
ament_target_dependencies( imu_node IMULib )
install( FILES imu_node DESTINATION bin )

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

install( TARGETS)

ament_package()
