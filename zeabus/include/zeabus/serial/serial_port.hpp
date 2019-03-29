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

#include    <stdio.h> // standard library of c language
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

            bool open_port();
            bool close_port();
            bool port_is_open();

            void set_name_port( std::string port_name );

            virtual unsigned int read_data( std::vector<unsigned char>* buffer 
                    , unsigned int size ) = 0;

            virtual unsigned int write_data( std::vector<unsigned char>* buffer
                    , unsigned int size ) = 0;

            // OP stand for option_port
            template < typename OP >bool set_options_port( OP data );

        protected:
            SerialPort( std::string port_name = "" );
            ~SerialPort();  
            std::string port_name; // this variable collect name of port will be use
            boost::asio::io_service io_service;
            boost::asio::serial_port io_port;
            // this variable use to mangage about value of error code
            boost::system::error_code error_code; 

    };

}

}

#endif
