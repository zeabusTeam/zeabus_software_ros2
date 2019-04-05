// FILE         :   serial_port.hpp
// AUTHOR       :   Supasan Komonlit
// CREATE DATE  :   2019, MARCH 21

// SENSOR OPTION DOCUMENTS
//      baud rate       : rate for send symbol of message. learn in DATA COMMUNICATION
//      flow control    : The ability to stop and restart flow without any loss of bytes
//      parity          : method of detecting error in transmission
//      stop bits       : stop bits sent at the end of every character
//      character_size  : size bits of character
//      reference       : https://www.tldp.org/HOWTO/Serial-HOWTO-4.html
//                        https://en.wikipedia.org/wiki/Serial_port#Parity
// Please if have question about boost lib have used in this file. 
//      You can contact to Supasan (GAP) by supasan.k@ku.th
//      if you are member of zeabus team can read in coda.io section Boost library
//      last way you can read by search on google and suggest https://www.boost.org

#include    <boost/asio.hpp>

#include    <boost/core/noncopyable.hpp> 

#include    <vector> //  use to make buffer for get data

#include    <iostream> // standard library of c++ language

#ifndef _ZEABUS_SERIAL_SERIAL_PORT_HPP__
#define _ZEABUS_SERIAL_SERIAL_PORT_HPP__

namespace _boost_errc = boost::system::errc;

namespace zeabus
{

namespace serial
{

    class SerialPort : private boost::noncopyable{
      
        public:

            bool open_port(); // return true if success to open port , other case is false
            bool close_port(); // return true if success to close port , other case is false
            bool port_is_open(); // return true if status of port is open , other case is false

            void set_name_port( std::string port_name ); // for public function set port name

            // for read and write data will different in detail by herit class
            virtual unsigned int read_data( std::vector<unsigned char>* buffer 
                    , unsigned int size ) = 0;

            virtual unsigned int write_data( std::vector<unsigned char>* buffer
                    , unsigned int size ) = 0;

            // because we want to compile this to library and reduce time of compile main code
            // that reason make we can use template to build below function
            bool set_option_port( boost::asio::serial_port_base::baud_rate data );
            bool set_option_port( boost::asio::serial_port_base::flow_control data );
            bool set_option_port( boost::asio::serial_port_base::parity data );
            bool set_option_port( boost::asio::serial_port_base::stop_bits data );
            bool set_option_port( boost::asio::serial_port_base::character_size data );

        protected: // this mode call only by inherit class
            SerialPort( std::string port_name = "" ); 
            ~SerialPort();  
            std::string port_name; // this variable collect name of port will be use
            boost::asio::io_service io_service; // each port have to port service
            boost::asio::serial_port io_port;
            // this variable use to mangage about value of error code
            boost::system::error_code error_code; 

    }; // class SerialPort

} // namespace serial

} // namespace zeabus

#endif
