// FILE         : bytes.cpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019 , APRIL 01

#include    <zeabus/convert/bytes.hpp>

namespace zeabus
{

namespace convert
{

namespace bytes
{

    bool vector_to_float( std::vector< unsigned char>* set_data 
            , float* result , unsigned int offset = 0 )
    {
        bool result = false;
        if( offset + 3 < set_data->size() )
        {
            data32 = ( ( (unsigned long int) ((*set_data)[offset] ) ) << 24 )
                    |( ( (unsigned long int) ((*set_data)[offset + 1] ) ) << 16 )
                    |( ( (unsigned long int) ((*set_data)[offset + 2] ) ) << 8 )
                    |( ( (unsigned long int) ((*set_data)[offset + 3] ) ) << 0 );
            memcpy( result , &data32 , 4 );
            result = true;
        }
        return result;
    }

    bool vector_to_double( std::vector< unsigned char>* set_data
            , double* result , unsigned int offset = 0 )
    {
        bool result = false;
        if( offset + 7 < set_data->size() )
        {
            data32 = ( ( (unsigned long long int) ((*set_data)[offset] ) ) <<  56 )
                    |( ( (unsigned long long int) ((*set_data)[offset + 1] ) ) << 48 )
                    |( ( (unsigned long long int) ((*set_data)[offset + 2] ) ) << 40 )
                    |( ( (unsigned long long int) ((*set_data)[offset + 1] ) ) << 32 )
                    |( ( (unsigned long long int) ((*set_data)[offset + 2] ) ) << 24 )
                    |( ( (unsigned long long int) ((*set_data)[offset + 1] ) ) << 16 )
                    |( ( (unsigned long long int) ((*set_data)[offset + 2] ) ) << 8 )
                    |( ( (unsigned long long int) ((*set_data)[offset + 3] ) ) << 0 );
            memcpy( result , &data64 );
            result = true;
        }
        return result;
    }

} // namespace bytes

} // namespace convert

} // namespace zeabus
