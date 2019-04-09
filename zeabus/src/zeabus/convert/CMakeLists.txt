add_library( Convert STATIC
    bytes.cpp   
    vector/one_byte.cpp 
    string/integer_type.cpp
)
ament_target_dependencies( Convert geometry_msgs )
