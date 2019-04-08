// FILE         : decode_string.cpp
// Author       : Supasan Komonlit
// Create on    : 2019, APRIL 09

#include    <zeabus/sensor/DVL/decode_string.hpp>

namespace zeabus
{

namespace sensor
{

namespace DVL
{

    // Pattern :BS,sXXXXX,sYYYYY,sZZZZZ,S
    void PD6_code_BS( std::string* message, int* vel_x, int* vel_y, int* vel_z, char* status )
    {
        std::string temp_message = "";    
        for( int count = 0 ; count < 6 ; count++ )
        {
            temp_message += (*message)[ 4 + count ];
        } // loop for... vel_x
        (void)zeabus::convert::string::to_integer( &temp_message , vel_x );

        temp_message = "";
        for( int count = 0 ; count < 6 ; count++ )
        {
            temp_message += (*message)[ 11 + count ];
        } // loop for... vel_x
        (void)zeabus::convert::string::to_integer( &temp_message , vel_y );

        temp_message = "";
        for( int count = 0 ; count < 6 ; count++ )
        {
            temp_message += (*message)[ 18 + count ];
        } // loop for... vel_x
        (void)zeabus::convert::string::to_integer( &temp_message , vel_z );

        *status = (*message)[ 25 ]; 
    } // function PD6_code_BS

    // Pattern :BI,sXXXXX,sYYYYY,sZZZZZ,sEEEEE,S
    void PD6_code_BI( std::string* message, int* vel_x, int* vel_y, int* vel_z
            , int* vel_error , char* status )
    {
        std::string temp_message = "";    
        for( int count = 0 ; count < 6 ; count++ )
        {
            temp_message += (*message)[ 4 + count ];
        } // loop for... vel_x
        (void)zeabus::convert::string::to_integer( &temp_message , vel_x );

        temp_message = "";
        for( int count = 0 ; count < 6 ; count++ )
        {
            temp_message += (*message)[ 11 + count ];
        } // loop for... vel_x
        (void)zeabus::convert::string::to_integer( &temp_message , vel_y );

        temp_message = "";
        for( int count = 0 ; count < 6 ; count++ )
        {
            temp_message += (*message)[ 18 + count ];
        } // loop for... vel_x
        (void)zeabus::convert::string::to_integer( &temp_message , vel_z );

        temp_message = "";
        for( int count = 0 ; count < 6 ; count++ )
        {
            temp_message += (*message)[ 25 + count ];
        } // loop for... vel_x
        (void)zeabus::convert::string::to_integer( &temp_message , vel_error );

        *status = (*message)[ 32 ]; 
    } // function PD6_code_BI
    

} // namespace DVL

} // namespace sensor

} // namespace zeabus
