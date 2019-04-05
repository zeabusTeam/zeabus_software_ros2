// FILE         :   synchronous_port.hpp
// AUTHOR       :   Supasan Komonlit
// CREATE DATE  :   2019, MARCH 22

#include    <zeabus/serial/serial_port.hpp>

// This file will derived to zeabus::serial::SerialPort that make me can include just one file.
// That mean this file we create class for connect to hardware by serial port connection.
// Type about time to read\write port have two is synchronous and asynchronous.
// This file use synchronous type to connect serial port.

#ifndef _ZEABUS_SERIAL_SYNCHRONOUS_PORT_HPP
#define _ZEABUS_SERIAL_SYNCHRONOUS_PORT_HPP

namespace zeabus
{

namespace serial
{
   class SynchronousPort : public SerialPort{

        public:
            SynchronousPort( std::string name_port = "" );

            virtual unsigned int read_data( std::vector<unsigned char>* buffer 
                    , unsigned int size );

            virtual unsigned int write_data( std::vector<unsigned char>* buffer
                    , unsigned int size );

    }; // class SynchronousPort

} // namespace serial

} // namespace zeabus

#endif 
