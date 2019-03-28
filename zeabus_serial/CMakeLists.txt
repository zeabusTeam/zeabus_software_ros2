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

install( TARGETS SynchronousPortLib DESTINATION bin ) 
install( TARGETS SynchronousPortLib LIBRARY DESTINATION lib )
install( FILES ${PROJECT_SOURCE_DIR}/src/synchronous_port.hpp 
        DESTINATION include/zeabus/serial )

ament_export_dependencies( Boost )
ament_export_include_directories( "${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/src")
ament_export_libraries( SynchronousPortLib )

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
