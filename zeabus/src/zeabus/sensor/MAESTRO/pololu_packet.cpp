// FILE         : plololu_packet.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 11

#include    <zeabus/sensor/MAESTRO/packet.hpp>

// This file will source code only packet for Pololu Protocol

namespace zeabus
{

namespace sensor
{

namespace MAESTRO
{

namespace POLOLU
{

    Packet::Packet( unsigned char init_byte , unsigned char device_number 
            , unsigned int reserve_size ) : BasePacket( reserve_size )
    {
        this->set_init_byte( init_byte );
        this->set_device_number( device_number );
    } // init function of Packet class 

    void Packet::set_device_number( unsigned char device_number )
    {
        this->device_number = device_number;
    } // function set_device_number

    void Packet::set_init_byte( unsigned char init_byte )
    {
        this->init_byte = init_byte;
    } // function set_init_byte

    void Packet::init_header( unsigned char command )
    {
        this->clear_member();
        zeabus::variadic::push_data( &(this->data) , this->init_byte , this->device_number 
                , command ); // push 3 byte set header device_number and command
    } // function init_header

    void Packet::push_vector_2_bytes( std::vector< unsigned short int >* data )
    {
        unsigned char low_bits;
        unsigned char high_bits;
        for( std::vector< unsigned short int>::iterator point = data->begin() ; 
                point != data->end() ; point++ )
        {
            low_bits = ( *point ) & 0x7F; // we want data 7 bits in 1 bytes
            high_bits = ( ( *point ) >> 7 ) & 0x7F; // shift right 7 bits get low_bits out
                    // and use only 7 bits in 1 bytes
            zeabus::variadic::push_data( &(this->data) , low_bits , high_bits );
        } // end for loop 
    } // function push_vector_2_bytes

} // namespace POLOLU

} // namespace MAESTRO

} // namespace sensor

} // namespace zeabus
