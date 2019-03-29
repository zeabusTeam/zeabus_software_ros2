// FILE         :   synchronous_port.hpp
// AUTHOR       :   Supasan Komonlit
// CREATE DATE  :   2019, MARCH 22

#include    <zeabus/serial/synchronous_port.h>

// This file will derived to zeabus::serial::SerialPort that make me can include just one file.
// That mean this file we create class for connect to hardware by serial port connection.
// Type about time to read\write port have two is synchronous and asynchronous.
// This file use synchronous type to connect serial port.

#ifdef __BUILD_HEADER_ZEABUS__

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

    }; 
}

}

#endif 
