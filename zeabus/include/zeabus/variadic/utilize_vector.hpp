// FILE         : utilize_vector.hpp
// ATUHOR       : Supasan Komonlit
// CREATE ON    : 2019, MARCH 30

// This file will use pattern template an varidic for utilize and apply with vector

#include    <vector>

#include    <stdio.h>
#include    <iostream>

#ifndef _ZEABUS_VARIADIC_UTILIZE_VECTOR_HPP__
#define _ZEABUS_VARIADIC_UTILIZE_VECTOR_HPP__

namespace zeabus
{
namespace variadic
{
    template< typename vector_type , typename single_type >
    void push_data( std::vector< vector_type >* buffer , single_type data )
    {
        buffer->push_back( (vector_type)data );
    }

    template< typename vector_type , typename single_type , typename... type_pack >
    void push_data( std::vector< vector_type >* buffer , single_type data , type_pack... pack )
    {
        push_data( buffer , data );
        push_data( buffer , pack... );
    }
}
}

#endif
