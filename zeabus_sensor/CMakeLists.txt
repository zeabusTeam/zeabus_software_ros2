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
find_package(Boost REQUIRED COMPONENTS)
find_package(rclcpp REQUIRED)

set( zeabus_serial /home/sevinar/zeabus_workspace/src/zeabus_software/zeabus_serial )

include_directories( include 
    ${zeabus_serial}/include 
    ${Boost_INCLUDE_DIRS} )

add_executable( imu_node 
    ${zeabus_serial}/src/serial_port.cpp
    ${zeabus_serial}/src/synchronous_port.cpp
    src/IMU/packet.cpp 
    src/IMU/connector.cpp 
    src/IMU/node.cpp 
    ) 
target_link_libraries( imu_node ${Boost_LIBRARIES})
ament_target_dependencies( imu_node ${Boost_LIBRARIES})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

install( TARGETS)

ament_package()
