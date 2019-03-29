cmake_minimum_required( VERSION 3.5 )
project( zeabus )

find_package( ament_cmake REQUIRED )
find_package( Boost REQUIRED  )

set( zeabus_source_path "${PROJECT_SOURCE_DIR}/src" )

include_directories( 
    "${zeabus_source_path}" 
    "${Boost_INCLUDE_DIR}"
    "${PROJECT_BINARY_DIR}"
)

configure_file(
    "${PROJECT_SOURCE_DIR}/zeabus_path.hpp.in"
    "${PROJECT_BINARY_DIR}/zeabus_path.hpp"
)

ament_export_include_directories( "${PROJECT_SOURCE_DIR}/include" )

add_subdirectory( src )

set( EXTRA_LIBS 
    SynchronousPort 
    IMUConnector 
)

ament_export_libraries( ${EXTRA_LIBS} )

install( DIRECTORY "${PROJECT_SOURCE_DIR}/include/" DESTINATION include )

install( TARGETS ${EXTRA_LIBS}
    ARCHIVE DESTINATION bin
    LIBRARY DESTINATION lib
)

ament_package()
