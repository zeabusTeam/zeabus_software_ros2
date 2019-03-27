// FILE         : synchronous_port.cpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, MARCH, 22

#include    <zeabus_serial/synchronous_port.hpp>

namespace zeabus
{

namespace serial
{

    SynchronousPort::SynchronousPort( std::string port_name ) : SerialPort( port_name ){}

    unsigned int SynchronousPort::read_data( std::vector<unsigned char>* buffer 
            , unsigned int size )
    {
        if( (*buffer).size() < size )
        {
            (*buffer).resize( size ); // must ensure your buffer have size can collect data
        }
        unsigned int size_data;
        do
        {   
            size_data = boost::asio::read( this->io_port , boost::asio::buffer( *buffer , size )
                    , this->error_code );
            if( this->error_code == _boost_errc::resource_unavailable_try_again 
                    || this->error_code == _boost_errc::interrupted )
            {
                printf("try to read data again\n");
            }
            else if( this->error_code == _boost_errc::success )
            {
                break;
            }
            else
            {
                printf("error in read data code is %ld\n" , this->error_code );
                size_data = 0;
            }
        }while( true );
        return size_data;
    }

    unsigned int SynchronousPort::write_data( std::vector<unsigned char>* buffer 
            , unsigned int size )
    {
        unsigned int size_data = boost::asio::write( this->io_port 
                , boost::asio::buffer( buffer , size ) , this->error_code );
        if( this->error_code != _boost_errc::success )
        {
            printf( "error in write data code is %ld\n" , this->error_code );
        }
        return size_data;
    }

}

}
