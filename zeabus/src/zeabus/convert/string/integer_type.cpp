// File         : integer_type.cpp
// Author       : Supasan Komonlit
// Create on    : 2019, APRIL 9

#include    <zeabus/convert/string.hpp>

namespace zeabus
{

namespace convert
{

namespace string
{
    // this file we collect about detail to convert string to

    bool to_integer( std::string* data , int* result )
    {
        char character; // for collect point char of data
        unsigned int running = 0 ; // for run in string
        signed int result_sign = 1;
        *result = 0;
        bool return_value = true; // for return convert and data are collect
        character = (*data)[ running ];
        // stop when return_value == false or stop when character point to last of string
        while( ( character != '\0' ) && return_value ) // stop when return_value == false
        {
            if( ( '0' <= character ) && ( character <= '9' ) ) // in case that is number
            {
                *result = ( ( (*result) * 10 ) +  ( character - '0') );
            }
            else
            {
                switch( character )
                {
                case '+' : // case we find '+' 
                    if( (*result) == 0 ) // that mean we never find number in this data 
                    {
                        result_sign = 1;
                    }
                    else // that mean we find sign between number
                    {
                        return_value = false;
                    }
                    break;
                }
                case '-' : // case we find '-'
                {
                    if( (*result) == 0 ) // that mean we never find number befor in this data
                    {
                        result_sign = -1
                    }
                    else
                    {
                        return_value = false;
                    }
                    break;
                }
                default :
                {
                    return_value = false;
                }
            }
            running++;
            character = (*data)[running];
        } // loop while
        if( return_value )
        {
            (*result) = (*result) * result_sign;
        }
        return return_value;

    } // function to_integer

} // namespace string

} // namespace convert

} // namespace zeabus
