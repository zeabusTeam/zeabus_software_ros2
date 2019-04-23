cmake_minimum_required(VERSION 3.5)
project(zeabus_sensor)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic )
endif()

find_package(ament_cmake REQUIRED)
find_package(zeabus REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(sensor_msgs REQUIRED)

set( zeabus_dir ${zeabus_DIR})
set( zeabus_include_dir ${zeabus_INCLUDE_DIRS})
set( zeabus_libraries ${zeabus_LIBRARIES})

configure_file(
    "${PROJECT_SOURCE_DIR}/zeabus_sensor_path.hpp.in"
    "${PROJECT_BINARY_DIR}/zeabus_sensor_path.hpp"
)

include_directories( ${zeabus_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} )

add_executable( imu_node src/imu_node.cpp)
ament_target_dependencies( imu_node ${zeabus_LIBRARIES} rclcpp sensor_msgs)
target_link_libraries( imu_node  
    ${zeabus_LIBRARIES}
    ${Boost_LIBRARIES} 
)

add_executable( dvl_node src/dvl_node.cpp)
ament_target_dependencies( dvl_node ${zeabus_LIBRARIES} rclcpp geometry_msgs)
target_link_libraries( dvl_node  
    ${zeabus_LIBRARIES} 
    ${Boost_LIBRARIES} 
)

install( TARGETS 
    imu_node 
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
