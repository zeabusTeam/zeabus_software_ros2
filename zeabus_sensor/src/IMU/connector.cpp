// FILE         : connector.cpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, MARCH 25

#include    <zeabus_sensor/IMU/connector.hpp>

namespace zeabus
{

namespace sensor
{

namespace IMU
{

    Connector::Connector( std::string port_name , unsigned int size ) : 
            SynchronousPort( portname ) , Packet( size )
    {
    }

    bool Connector::set_idle()
    {
        bool result = false;
        unsigned int num_check;
        this->init_header(); // Init header file for buffer
        this->push_data( LORD_MICROSTRAIN::COMMAND::BASE::DESCRIPTOR , 0x02 
                , 0x02 , LORD_MICROSTRAIN::COMMAND::BASE::IDLE );
        this->add_check_sum();
#ifdef _PRINT_DATA_CONNECTION_
        this->print_data( "data for set idle");
#endif

#ifdef _CHECK_MEMORY_
        printf("Set idle command detail of buffer is " );
        this->print_check_memory();
#endif

        num_check = this->write_data( &(this->data) , (this->data).size() );
        if( num_check != (this->data).size() )
        {
#ifdef _ERROR_TYPE_
            printf("Print error type amont valur to writing and can wiite %ld\n" , numcheck );
#endif
        }
        else
        {
            if( this->read_reply( LORD_MICROSTRAIN::COMMAND::BASE::DESCRIPTOR ) )
            {
#ifdef _CHECK_RESPONSE_
            this->print_data( "data for reply" );
#endif
                if( this->check_sum() )
                {
                    // This is one case to can make result is true
                    result = ( *( (this->data).end() - 2 ) == 0x00 );
                }
            }
        }
        return result;
    }

    bool Connector::ping()
    {
        bool result = false;
        unsigned int num_check;
        this->init_header();
        this->push_data( LORD_MICROSTRAIN::COMMAND::BASE::DESCRIPTOR , 0x02 , 0x02 
                , LORD_MICROSTRAIN::COMMAND::BASE::PING );
        this->add_check_sum();
#ifdef _PRINT_DATA_CONNECTION_
        this->print_data( "data for ping");
#endif

#ifdef _CHECK_MEMORY_
        printf("Ping command detail of buffer is ");
        this->print_check_memory();
#endif
        num_check = this->write_data( &(this->data) , (this->data).size() );
        if( num_check != (this->data).size() )
        {
#ifdef _ERROR_TYPE_
            printf("Print error type amont value to writing and can write %ld\n" , numcheck );
#endif
        }
        else
        {
            if( this->read_reply( LORD_MICROSTRAIN::COMMAND::BASE::DESCRIPTOR ) )
            {
#ifdef _CHECK_RESPONSE_
            this->print_data( "data for reply" );
#endif
                if( this->check_sum() )
                {
                    // This is one case to return true we check descriptor checksum and ACK
                    result = ( *( ( this->data).end() - 2 ) == 0x00 ); 
                }
            }
        }
        return result;
    }

}

}

}
