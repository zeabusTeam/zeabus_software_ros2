cmake_minimum_required( VERSION 3.5 )
project( zeabus )

find_package( ament_cmake REQUIRED )
find_package( Boost REQUIRED  )

include_directories( 
    "${PROJECT_SOURCE_DIR}/src/" 
    "${Boost_INCLUDE_DIR}"
)

ament_export_include_directories( "${PROJECT_SOURCE_DIR}/include" )

add_subdirectory( src )

set( EXTRA_LIBS SynchronousPort IMUConnector )

ament_export_libraries( ${EXTRA_LIBS} )

install( DIRECTORY "${PROJECT_SOURCE_DIR}/include/" DESTINATION include )

install( TARGETS ${EXTRA_LIBS}
    ARCHIVE DESTINATION bin
    LIBRARY DESTINATION lib
)

ament_package()
