// FILE         :   synchronous_port.hpp
// AUTHOR       :   Supasan Komonlit
// CREATE DATE  :   2019, MARCH 22

#include    <zeabus/serial/serial_port.hpp>

// This file will derived to zeabus::serial::SerialPort that make me can include just one file.
// That mean this file we create class for connect to hardware by serial port connection.
// Type about time to read\write port have two is synchronous and asynchronous.
// This file use synchronous type to connect serial port.

// MACRO DETAIL
// _SHOW_INDIVIDUAL_CHAR_   : this for read_data( std::string* ) this show data you haved read

#ifndef _ZEABUS_SERIAL_SYNCHRONOUS_PORT_HPP
#define _ZEABUS_SERIAL_SYNCHRONOUS_PORT_HPP

namespace zeabus
{

namespace serial
{
   class SynchronousPort : public SerialPort{

        public:
            SynchronousPort( std::string name_port = "" );

            // read_data & write_data we have decision to use overload function
            // but in function parameter is std::string 
            // when connect to serial will use read_data by vector< unsigned char >
            unsigned int read_data( std::vector<unsigned char>* buffer 
                    , unsigned int size );

            unsigned int write_data( std::vector<unsigned char>* buffer
                    , unsigned int size );

            unsigned int read_data( std::string* message );
            unsigned int write_data( std::string* message ); 

    }; // class SynchronousPort

} // namespace serial

} // namespace zeabus

#endif 
