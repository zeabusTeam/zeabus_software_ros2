// FILE         : plololu_connector.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 11

#include    <zeabus/sensor/MAESTRO/connector.hpp>

namespace zeabus
{

namespace sensor
{

namespace MAESTRO
{

namespace POLOLU
{
    // Case no data
    Connector::Connector( ) : Packet() , SynchronousPort()
    {
        ; // make default value to setting variable 
    } // init function case 1

    // Case have data for serial port only
    Connector::Connector( std::string port_name ) : Packet() , SynchronousPort( port_name )
    {
        ; // Make default value of packet to do something
    } // init function case 2

    // Case have data for packet only
    Connector::Connector( unsigned char init_byte , unsigned char device_number 
            , unsigned int reserve_size ) : Packet( init_byte , device_number , reserve_size )
            , SynchronousPort( )
    {
        ; // Please ensure you have use function for set port name before open port
    } // init function case 3

    Connector::Connector( std::string port_name , unsigned char init_byte 
            , unsigned char device_number , unsigned int reserve_size ) : Packet( init_byte 
                    , device_number , reserve_size ) , SynchronousPort( port_name )
    {
        ; // for case you set start data all
    } // init function case 4

    bool Connector::set_multiple_targets( std::vector< unsigned short int >* target_bits
            , unsigned char first_channel )
    {
        bool result = false;
        this->init_header( 
                zeabus::sensor::MAESTRO::protocol::POLOLU::COMMAND_SET_MULTIPLE_TARGETS );
        zeabus::variadic::push_data( &(this->data) , target_bits->size() , first_channel );
        this->push_vector_2_bytes( target_bits );
        unsigned int num_check = this->write_data( &(this->data) , (this->data).size() );
        if( num_check == (this->data).size() )
        {
            result = true;
        } // if condition result = true
        return result;
    } // function set_multiple_targets

} // namespace POLOLU

} // namespace MAESTRO

} // namespace sensor

} // namespace zeabus
