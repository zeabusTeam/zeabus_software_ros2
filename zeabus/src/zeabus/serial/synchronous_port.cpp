// FILE         : synchronous_port.cpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, MARCH, 22

#include    <zeabus/serial/synchronous_port.hpp>

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
                std::cout   << "Port unavailable for reading will try again\n";
            }
            else if( this->error_code == _boost_errc::success )
            {
                break;
            }
            else
            {
                std::cout   << "Failure to reading error_code is " 
                            << (this->error_code).value() << "\n";
                size_data = 0;
            }
        }while( true );
        return size_data;
    } // function read_date

    unsigned int SynchronousPort::write_data( std::vector<unsigned char>* buffer 
            , unsigned int size )
    {
        unsigned int size_data = boost::asio::write( this->io_port 
                , boost::asio::buffer( *buffer , size ) , this->error_code );
        if( this->error_code != _boost_errc::success )
        {
            std::cout   << "Failure for writing data to Synchronous port error_code is "
                        << (this->error_code).value() << "\n" ;
        }
        return size_data;
    } // function write_data

} // namespace serial

} // namespace zeabus

