// FILE         : base_packet.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 11

#include    <zeabus/sensor/MAESTRO/packet.hpp>

// This file will source code only BasePacket

namespace zeabus
{

namespace sensor
{

namespace MAESTRO
{

    BasePacket::BasePacket( unsigned int reserve_size )
    {
        this->reserve( reserve_size );
    } // init function of BasePacket

    void BasePacket::reserve( unsigned int size )
    {
        (this->data).reserve( size );
    } // function reserve

    void BasePacket::resize( unsigned int size )
    {
        (this->data).resize( size );
    } // function resize

    void BasePacket::clear_member()
    {
        this->resize( 0 );
    } // function clear_member

    void BasePacket::fit_capacity()
    {
        (this->data).shrink_to_fit();
    } // function fit_capacity

    void BasePacket::print_data( std::string message )
    {
        if( message == "") 
        {   
            std::cout << "Data on packet : ";
        }   
        else
        {   
            std::cout << message << " : ";
        }   
        std::cout  << std::hex; // we will print number by hexademal
        for( std::vector<unsigned char>::iterator point = (this->data).begin() ; 
                point != (this->data).end() ; point++ )
        {   
            std::cout << *point << " ";
        }   
        std::cout << std::dec << std::endl;
    } // function print_data

    void BasePacket::print_check_memory()
    {
        std::cout << "Now packet have number of element : " << (this->data).size()
                << "\n\tcapacity : " << (this->data).capacity() << "\n";
    } // function print_check_memory

} // namespace MARSTRO

} // namespace sensor

} // namespace zeabus
