cmake_minimum_required(VERSION 3.5)
project(zeabus_serial)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED )
find_package(Boost REQUIRED )

include_directories( include ${Boost_INCLUDE_DIRS})

add_library( SynchronousPortLib SHARED
    src/serial_port.cpp
    src/synchronous_port.cpp
)
target_link_libraries( SynchronousPortLib ${Boost_LIBRARIES})

ament_export_dependencies(
    Boost
)

ament_export_include_directories( include )
ament_export_libraries( SynchronousPortLib )

set( synchronous_port_header "${PROJECT_SOURCE_DIR}/src/synchronous_port.hpp")

install(
    FILES ${synchronous_port_header}
    DESTINATION include/zeabus/sensor
)

install(
    TARGETS SynchronousPortLib
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
