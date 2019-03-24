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

include_directories( include )

add_library( imu_handle SHARED
    src/IMU/packet.cpp )
ament_target_dependencies( imu_handle zeabus_serial )

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
