// FILE         : connector.cpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, MARCH 25

#include    <zeabus_sensor/IMU/connector.hpp>

// All code have reference from data-sheet of 3dm-gx5-45_data-commmunication_protocol.pdf

namespace zeabus
{

namespace sensor
{

namespace IMU
{

    Connector::Connector( std::string port_name , unsigned int size ) : 
            SynchronousPort( portname ) , Packet( size )
    {
        (this->reader_buffer).reserve( (unsigned int) 100 );
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
            printf("Print error type amont valur to writing and can wiite %ld\n" , num_check );
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
                    result = ( *( (this->data).end() - 3 ) == 0x00 );
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
            printf("Print error type amont value to writing and can write %ld\n" , num_check );
#endif
            ; // In case can't write data equal size of packet
        }
        else
        {
            if( this->read_reply( LORD_MICROSTRAIN::COMMAND::BASE::DESCRIPTOR ) )
            {
#ifdef _CHECK_RESPONSE_
                this->print_data( "data for reply ping" );
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

    bool Connector::resume() // unlock idle mode to data stream mode page 40 
    {
        bool result = false;
        unsigned int num_check;
        this->init_header();
        this->push_data( LORD_MICROSTRAIN::COMMAND::BASE::DESCRIPTOR , 0x02 , 0x02
                , LORD_MICROSTRAIN::COMMAND::BASE::RESUME );
        this->add_check_sum();
#ifdef _PRINT_DATA_CONNECTION_
        this->print_data( "data for resume");
#endif

#ifdef _CHECK_MEMORY_
        printf("Resume command detail of buffer is ");
        this->print_check_memory();
#endif
        num_check = this->write_data( &(this->data) , (this->data).size() );
        if( num_check != (this->data).size() )
        {
#ifdef _ERROR_TYPE_
            printf("Print error type amont value to writing and can write %ld\n" , num_check );
#endif
            ; // if don't define _ERROR_TYPE_ will make is blank statement
        }
        else
        {
            if( this->read_reply( LORD_MICROSTRAIN::COMMAND::BASE::DESCRIPTOR ) )
            {
#ifdef _CHECK_RESPONSE_
                this->print_data( "data for reply resume");
#endif
                if( this->check_sum() )
                {
                    result = ( *( (this->data).end() - 2 ) == 0x00 );
                }
            }
        }
        return result;
    }

    void Connector::set_IMU_rate( int rate )
    {
        this->front_rate = (unsigned char ) ( ( (rate) & 0xff00 ) >> 8 );
        this->back_rate = (unsigned char) ( rate & 0xff );
    }

    bool Connector::set_IMU_message_format( unsigned char first_type , unsigned char second_type
            , unsigned char third_type ) // This function page 51
    {
        bool result = false;
        unsigned int num_check;
        // Part prepare data for writing
        this->init_header();
        this->push_data( LORD_MICROSTRAIN::COMMAND::SENSOR::DESCRIPTOR , 0x0d , 0x0d
                , LORD_MICROSTRAIN::COMMAND::SENSOR::IMU_MESSAGE_FORMAT , 0x01 , 0x03 
                , first_type , this->front_rate , this->back_rate 
                , second_type , this->front_rate , this->back_rate 
                , third_type , this->front_rate , this->back_rate );
        this->add_check_sum();
#ifdef _PRINT_DATA_CONNECTION_
        this->print_data("Command set IMU message type");
#endif
#ifdef _CHECK_MEMORY_
        printf("Set IMU message command detail of buffer is ");
        this->print_check_memory();
#endif
        num_check = this->write_data( &(this->data) , (this->data).size() );
        if( num_check != (this->data).size() )
        {
#ifdef _ERROR_TYPE_
            printf("Set IMU message format error number of data\n")
#endif  
            ; // in case can write data equal lenght of packet
        }
        else
        {
            if( this->read_reply( LORD_MICROSTRAIN::COMMAND::SENSOR::DESCRIPTOR ) )
            {
#ifdef _CHECK_RESPONSE_
                this->print_data("data for reply set IMU message")
#endif
                if( this->check_sum() )
                {
                    result = ( *( (this->data).end() - 2 ) == 0x00 );
                }
            }
        }
        return result;
    }

    bool Connector::enable_IMU_data_stream()
    {
        bool result = false;
        unsigned int num_check;
        this->init_header();
        this->push_data( LORD_MICROSTRAIN::COMMAND::SENSOR::DESCRIPTOR , 0x0a 
            , 0x05 , LORD_MICROSTRAIN::COMMAND::SENSOR::CONTINUOUS , 0x01 , 0x01 , 0x01 
            , 0x05 , LORD_MICROSTRAIN::COMMAND::SENSOR::CONTINUOUS , 0x01 , 0x03 , 0x00 );
        this->add_check_sum();
#ifdef _PRINT_DATA_CONNECTION_
        this->print_data("Command set enable IMU AND Estimate filter");
#endif
#ifdef  _CHECK_MEMORY_
        printf("enable stream command detail of buffer is ");
        this->print_check_memory();
#endif
        num_check = this->write_data( &(this->data) , (this->data).size());
        if( num_check != (this->data).size() )
        {
#ifdef _ERROR_TYPE_
            printf("Enable message error number of data\n")
#endif
            ; // will return false for can write == want write
        }
        else
        {
            if( this->read_reply( LORD_MICROSTRAIN::COMMAND::SENSOR::DESCRIPTOR ) )
            {
#ifdef _CHECK_RESPONSE_
                this->print_data( "data for reply enable data")
#endif
                if( this->check_sum() )
                {
                    result = ( *( (this->data).end() - 3 ) == 0x00 ) 
                            && ( *( (this->data).end() - 8 ) == 0x00 );
                }
            }
        }
        return result;
    }

    bool Connector::resume()
    {
        bool result = false;
        unsigned int num_check;
        this->init_header();
        this->push_data( LORD_MICROSTRAIN::COMMAND::BASE::DESCRIPTOR , 0x02 
                , 0x02 , LORD_MICROSTRAIN::COMMAND::BASE::RESUME );
        this->add_check_sum();
#ifdef _PRINT_DATA_CONNECTION_
        this->print_data("Command for resume device");
#endif
#ifdef _CHECK_MEMORY_
        printf("resume device command detail of buffer is");
        this->print_check_memory();
#endif
        num_check = this->write_data( &(this->data) , (this->data).size() );
        if( num_check != ( this->data).size() )
        {
#ifdef  _ERROR_TYPE_
            printf("resume error from data can write\n")
#endif
            ; // will return false for can write != want write
        }
        else
        {
            if( this->read_reply( LORD_MICROSTRAIN::COMMAND::SENSOR::DESCRIPTOR ) )
            {
#ifdef _CHECK_RESPONSE_
                this->print_data( "data for reply resume")
#endif
                if( this->check_sum() )
                {
                    result = ( *( (this->data).end() - 3 ) == 0x00 );
                }
            }
        }
        return result;
    }

    void Connector::init_header()
    {
        this->clear_member();
        this->push_data( 0x75 , 0x65 );
    }

    bool read_reply( unsigned char descriptor_byte ,unsigned int max_round )
    {
        bool result = true;
        for( unsigned int round = 0 ; ( round < max_round ) && result ; round++ )
        {
            this->reader_buffer.resize( 1 );
            for( unsigned int individual = 0 ;  individual < 5 ; individual++ )
            {
                (void)this->read_data( &(this->reader_buffer) , 1 );
                if( (this->read_data)[0] == 'u' )
                {
                    individual = 4;
                } 
                else if( individual == 4 )
                {
                    result = false;
                }
                else
                {
                    ; // for MISRA C++ 
                }
            }
            if( result )
            {
                (void)this->read_data( &(this->reader_buffer) , 1 );
                if( (this->read_data)[0] != 'e' )
                {
                    continue;
                }
                if( result )
                {
                    this->init_header();  
                }
                (this->reader_buffer).resize( 2 );
                (void)this->read_data( &(this->reader_buffer) , 2 );
                this->push_vector( &(this->reader_buffer) );
                (this->reader_buffer).resize( (this->data)[3] );
                (void)this->read_data( &(this->reader_buffer) , (this->reader_buffer).size() );
                this->push_vector( &(this->reader_buffer) );
                (this->reader_buffer).resize( 2 );
                (void)this->read_data( &(this->reader_buffer) , 2 );
                this->push_vector( *(this->reader_buffer) );
                if( (this->data)[2] == descriptor_byte )
                {
                    result = true;
                } 
                round = max_round; 
            }
        }
        return result;
    }

    bool Connector::read_stream()
    {
        bool result = this->read_reply( 0x80 );
#ifdef _CHECK_RESPONSE_
        this->print_data( "streamming data");
#endif
        if( result )
        {
            result = this->check_sum();
        }
        return result; 
    } 

}

}
