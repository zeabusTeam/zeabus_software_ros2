// File         : connector.cpp
// Author       : Supasan Komonlit
// Create on    : 2019, APRIL 08

#include    <zeabus/sensor/DVL/connector.hpp>

namespace zeabus
{

namespace sensor
{

namespace DVL
{

    Connector::Connector( std::string port_name ) : SynchronousPort( port_name )
    {
        ; //nothing interface to set port_name
    }

    // this file we will enusre you have to open port before run setting
    bool Connector::set_idle( unsigned int limit_round )
    {
        std::string message = "===";
        unsigned int count = 0;
        bool result = false;
        (void)this->write_data( &message );
#ifdef _PRINT_DATA_CONNECTION_
            std::cout << "COMMAND TO DVL " << message << std::endl;
#endif // _PRINT_DATA_CONNECTION_
        do
        {
            count++; // count round to wait comand
            (void)this->read_data( &message );
        }while( message != "Explorer DVL" && count < limit_round );
        if( count < limit_round ) // if true that mean have correct response form dvl
        {
#ifdef _PRINT_DATA_CONNECTION_
            std::cout << message << std::endl;
#endif // _PRINT_DATA_CONNECTION_
            (void)this->read_data( &message );
#ifdef _PRINT_DATA_CONNECTION_
            std::cout << message << std::endl;
#endif // _PRINT_DATA_CONNECTION_
            (void)this->read_data( &message );
#ifdef _PRINT_DATA_CONNECTION_
            std::cout << message << std::endl;
#endif // _PRINT_DATA_CONNECTION_ 
            (void)this->read_data( &message );
#ifdef _PRINT_DATA_CONNECTION_
            std::cout << message << std::endl;
#endif // _PRINT_DATA_CONNECTION_
            result = true;
        } // condition count < limit_round
        return result;
    } // function set_idle

    bool Connector::load_parameter( std::string data ) // formate data is CRn
    {
        std::string message = "CR" + data + "\n";
        unsigned int size = this->write_data( &message );
        bool result = false;
#ifdef _PRINT_DATA_CONNECTION_
        std::cout   << "COMMAND TO DVL " << message 
                    << " and size is " << size << std::endl;
#endif // _PRINT_DATA_CONNECTION_
        (void)this->read_data( &message );
        (void)this->read_data( &message );
        if( size == 4 ) 
        {
            result = true;
        }
        return result;
    } // function load_parameter

    bool Connector::send_message( std::string* data , unsigned int size_check )
    {
        unsigned int size = this->write_data( data );
        bool result = false;
        if( size == size_check )
        {
            result = true;
        }
#ifdef _PRINT_DATA_CONNECTION_
        std::cout   << "COMMAND TO DVL " << data 
                    << " and size is " << size << std::endl;
#endif // _PRINT_DATA_CONNECTION_
        return result;
    }

    bool Connector::bottom_track( std::string data ) // format data is BPnnn
    {
        std::string message = "BP" + data + "\n";
        return this->send_message( &message , 6 );
    } // function bottom_track

    bool Connector::max_depth( std::string data ) // formate data is BXnnnnn
    {
        std::string message = "BX" + data + "\n";
        return this->send_message( &message , 8 );
    } // function max_depth

    bool Connector::set_heading( std::string data ) // formate EAsnnnnn
    {
        std::string message = "EA" + data + "\n";
        unsigned int size = this->write_data( &message );
        bool result = false;
        return this->send_message( &message , 9 );
    } // function set_heading

    bool Connector::set_salinty( std::string data ) // format ESnn
    {
        std::string message = "ES" + data + "\n";
        return this->send_message( &message , 5 );
    } //  function set_salinty

    bool Connector::time_per_ensemble( std::string data ) // format TEhh:mm:ss.ff
    {
        std::string message = "TE" + data + "\n";
        return this->send_message( &message , 14 );
    } // function time_per_ensemble

    bool Connector::time_between_pings( std::string data ) // format TPmm:ss.ff
    {
        std::string message = "TP" + data + "\n";
        return this->send_message( &message , 11 );
    } // function time_between_pings

    bool Connector::ping_per_ensemble( std::string data ) // format WPnnnnn
    {
        std::string message = "WP" + data + "\n";
        return this->send_message( &message , 8 );
    } // function ping_per_ensemble

    bool Connector::data_stream( std::string data) // format PDn
    {
        std::string message = "PD" + data + "\n";
        return this->send_message( &message , 4 );
    } // function data_stream

    bool Connector::save_parameter()
    {
        std::string message = "CK\n";
        return this->send_message( &message , 3 );
    } // function save_parameter

    bool Connector::resume()
    {
        std::string message = "CS\n";
        return this->send_message( &message , 3 );
    } // function resume

} // DVL

} // namespace sensor

} // namespace zeabus
