// FILE         : LORD_IMU_COMMUNICATION.hpp
// AUTHOR       : Supasan Komonlit
// CREATE DATE  : 2019, MARCH , 22

#include    <iostream>

// This file we collect about protocol data to connect with LORD microstrain IMU 3dm-gx5-45
// we reference from 3dm-gx4-45_data_communicatio_protocaol_manual.pdf

#ifndef _ZEABUS_SENSOR_IMU_LORD_IMU_COMMUNICATION_HPP__
#define _ZEABUS_SENSOR_IMU_LORD_IMU_COMMUNICATION_HPP__

namespace zeabus
{

namespace sensor
{

namespace IMU
{

namespace LORD_MICROSTRAIN
{
    namespace COMMAND
    {
        namespace BASE
        {
            static const unsigned char DESCRIPTOR = 0x01;
            static const unsigned char PING = 0x01;
            static const unsigned char IDLE = 0x02;
            static const unsigned char GET_INFORMATIOn = 0x03;
            static const unsigned char GET_DESCRIPTOR = 0x04;
			static const unsigned char RESUME = 0x06;
			static const unsigned char EXTENDED_DEVICE_DESCRIPTOR = 0x07;
			static const unsigned char GPS_TIME_UPDATE = 0x72;
			static const unsigned char DEVICE_RESET = 0x7E;	
        }

        namespace SENSOR
        {
			static const unsigned char DESCRIPTOR = 0x0C;
			static const unsigned char POLL_IMU_DATA = 0x01;
			static const unsigned char POLL_GNSS_DATA = 0x02;
			static const unsigned char POLL_ESTIMATION_FILTER_DATA = 0x03;
			static const unsigned char GET_IMU_DATA_BASE_RATE = 0x06;
			static const unsigned char GET_GNSS_DATA_BASE_RATE = 0x07;
			static const unsigned char IMU_MESSAGE_FORMAT = 0x08;
			static const unsigned char GNSS_MESSAGE_FORMAT = 0x09;
			static const unsigned char ESTIMATION_FILTER_MESSAGE_FORMAT = 0x0A;
			static const unsigned char CONTINUOUS = 0x11;
        }
    }

    namespace DATA
    {
        namespace IMU_DATA_SEt
        {
			static const unsigned char DESCRIPTOR = 0x80;
			static const unsigned char SCALED_ACCELEROMETER_VECTOR = 0x04;
			static const unsigned char SCALED_GYRO_VECTOR = 0x05;
			static const unsigned char SCALED_MAGNETOMETER_VECTOR = 0x06;
			static const unsigned char SCALED_AMBIENT_PRESSURE = 0x17;
			static const unsigned char DELTA_THETA_VECTOR = 0x7;
			static const unsigned char DELTA_VELOCITY_VECTOR = 0x08;
			static const unsigned char CF_ORIENTATION_MATRXI = 0x09;
			static const unsigned char CF_QUATERNION = 0x0A;
			static const unsigned char CF_EULER_ANGLES = 0x0C;
			static const unsigned char CF_STABILIZED_MAG_VECTOR_NORTH = 0x10;
			static const unsigned char CF_STABILIZED_ACCEL_VECTOR_UP = 0x11;
			static const unsigned char GPS_CORRELATION_TIMESTAMP = 0x12;
        }
    }

}

}

}

}

#endif
