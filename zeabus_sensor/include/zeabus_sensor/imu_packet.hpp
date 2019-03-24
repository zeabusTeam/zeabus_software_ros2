// FILE         : imu_packet.hpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, MARCH , 22

#include    <zeabus_sensor/LORD_IMU_COMMUNICATION.hpp> 
// include protocol of lord microstrain 3dm-gx5-45

#include    <vector> // include c++ library for make a buffer to use in main part of packet

#include    <stdio.h> // standard library of c language 
// we include this because we want to use printf
#include    <iostream> // standard library of c++ language

namespace zeabus
{

namespace sensor
{

namespace IMU
{

    class Packet
    {
        public:
            void print_check_memory(); // this function for check about size of vector

            bool check_sum();

            void add_check_sum();

            void fit_capacity();

            void clear_member();

            void resize( unsigned int number );

            // For push data we use pattern of variadic function
            template< typename type_single >
            void push_data( type_single data_single );

            template< typename type_single , typename... type_pack >
            void push_data( type_single data_single , type_pack data_pack );

        protected:
            std::vector< unsigned char > data; // use to collect buffer
 
            unsigned long int data_4_byte( int offset , bool result ); 
            // use this when you want to add 4 byte or 4 member to one variable

    };

}

}
}
