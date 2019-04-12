// FILE         : packet.cpp
// AUTHOR       : Supasan Kommonlit
// CREATE DATE  : 2019, MARCH 24

#include    <zeabus/sensor/IMU/packet.hpp>

namespace zeabus
{
namespace sensor
{
namespace IMU
{
    Packet::Packet( unsigned int size )
    {
        this->reserve( size );
    }

    void Packet::print_check_memory()
    {
        std::cout << "Now packet have number of element : " << (this->data).size() 
                << "\n\tcapacity : " << (this->data).capacity() << "\n";
    }

    bool Packet::check_sum( bool self_check )
    {
        unsigned int size = (this->data).size();
        bool result = false;
        if( self_check )
        {
            this->find_check_sum( size - 2 );
        }
        if( (this->data)[ size - 2 ] == (this->MSB) && (this->data)[ size - 1 ] == (this->LSB) )
        {
            result  = true;
        }
        else
        {
            ; // Have statement when you define macro _CHECK_RESPONSE_
        }
        return result;
    }

    void Packet::add_check_sum( )
    {
        this->find_check_sum( (this->data).size() );
        variadic::push_data( &(this->data) , this->MSB , this->LSB ); 
    }

    // This will use solution for find check sum in IMU Lord Microstrain protocal
    // until first data/member to last data/member (in parameter) 
    // collect checksum to MSB LSB variable
    void Packet::find_check_sum( unsigned int size_data )
    {
        this->MSB = 0;
        this->LSB = 0;
        for( unsigned int run_number = 0 ; run_number < size_data ; run_number++ )
        {
            (this->MSB) += (this->data)[run_number];
            (this->LSB) += (this->MSB);
        }
    }

    // This will resize packet to zero member
    void Packet::clear_member()
    {
        (this->data).resize( 0 );
    }

    // This will reallocate capacity to fit with size of member
    void Packet::fit_capacity()
    {
        (this->data).shrink_to_fit();
    }

    // This will resize of packet to value of size 
    void Packet::resize( unsigned int size )
    {
        (this->data).resize( size );
    }

    // We will reserve allocate capacity for this packet
    void Packet::reserve( unsigned int size )
    {
        (this->data).reserve( size );
    }

    // We will make 4 bytes to 1 data ( 32 bits )
    unsigned long int Packet::data_4_byte( int offset )
    {
        return ( (unsigned long int) (this->data)[offset] ) << 24 
                | ( (unsigned long int ) (this->data)[offset + 1 ] << 16 )
                | ( (unsigned long int ) (this->data)[offset + 2 ] << 8 )
                | ( (unsigned long int ) (this->data)[offset + 3 ] );
    }

    // We will print all data in packet follow your message 
    void Packet::print_data( std::string message )
    {
        if( message == "")
        {
            std::cout << "Data on buffer : ";
        }
        else
        {
            std::cout << message << " : ";
        }
        std::cout  << std::hex ; // we will print number by hexademal
        for( std::vector<unsigned char>::iterator point = (this->data).begin() ; 
                point != (this->data).end() ; point++ )
        {
            std::cout << (0xff & *point) << " "; // have to and because focuse on 2 bytes
        }
        std::cout << std::dec << std::endl;
    }

    void Packet::push_vector( std::vector<unsigned char>* data_vector )
    {
        for( std::vector<unsigned char>::iterator point = data_vector->begin() ; 
                point != data_vector->end() ; point++ )
        {
            (this->data).push_back( *(point) );
        }
    }

    unsigned int Packet::size_member()
    {
        return (this->data).size();
    }

    unsigned char Packet::access_data( unsigned int position )
    {
        return (this->data)[ position ];
    }

}

}

}
