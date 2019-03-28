// FILE         : serial_port.cpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, MARCH, 22

#include    <zeabus/serial/serial_port.hpp>

namespace zeabus
{

namespace serial
{

    SerialPort::SerialPort( std::string port_name ) : io_port( this->io_service )
    {
        this->set_name_port( port_name );
    }

    SerialPort::~SerialPort()
    {
        if( this->port_is_open() )
        {
            (void)this->close_port();
        }
    }

    bool SerialPort::open_port()
    {
        bool result;
        try
        {
            this->io_port.open( this->port_name );
            result = true;
        }
        catch( const std::exception& error_message )
        {
            result = false;
        }
        return result;
    }

    bool SerialPort::close_port()
    {
        bool result;
        this->io_port.close( this->error_code );
        if( this->error_code == _boost_errc::success )
        {
            result = true;
        }
        else
        {
            result = false;
            printf( "Failure close port %s\n" , this->port_name.c_str() );
        }
        return result;
    }

    bool SerialPort::port_is_open()
    {
        return this->io_port.is_open();
    }

    void SerialPort::set_name_port( std::string port_name )
    {
        this->port_name = port_name;
    }

    template < typename OP >bool SerialPort::set_options_port( OP data )
    {
        bool result;
        this->io_port.set_option( data , this->error_code );
        if( this->error_code != _boost_errc::success )
        {
            printf( "Failure set option %s\n" , this->port_name.c_str() );
            result = false;
        }
        else
        {
            result = true;
        }
        return result;
    }

}

}
