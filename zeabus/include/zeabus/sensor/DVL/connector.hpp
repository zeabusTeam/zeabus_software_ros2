// File         : connecter.hpp
// Author       : Supasan Komonlit
// Create on    : 2019, APRIL 07

#include    <iostream> // Standard library for c++

#include    <zeabus/serial/synchronous_port.hpp> // Use to connect DVL

// DVL use string to set or connect with hardware 
// we reference data for ExplorerDVL Operation Manual.pdf

// Macro detail will print data for your purpose
//      _PRINT_DATA_CONNECTION_ print all data you want to write and have to read

#ifndef _ZEABUS_SENSOR_DVL_CONNECTOR_HPP__
#define _ZEABUS_SENSOR_DVL_CONNECTOR_HPP__

namespace zeabus
{

namespace sensor
{

namespace DVL
{

    class Connector : public zeabus::serial::SynchronousPort
    {

        public:
            Connector( std::string port_name = "" );

            bool set_idle( unsigned int limit_round = 30 ); // use this for stop streaming

            // Page 129 : load parameter 
            // formate CRn
            //      n = 0 <user setting> and 1 <factory setting>
            bool load_parameter( std::string data = "1" );

            // set number of bottom-track pings to average together in each data ensemble
            // Page 119 format BPnnn 
            //      nnn = 0 to 999 pings
            // set number of bottom-track pings to average together before sending/recording
            bool bottom_track( std::string data = "001" );
            
            // Page 120 : set maximum tracking depth in decimeters unit ( meters * 10 )
            // example is depth in area deployment is 20 meter  set 210 metes
            // format BXnnnnn
            bool max_depth( std::string data = "01000");

            // Page 133 : set heading of sensor to forward robot 
            // look number at hardward  4 to 3 is Y axis to x axis of robot
            // and use ENU to position or negative
            // format EAsnnnnn
            //      s is <+> , <->
            //      nnnnn = 00000 to 18000
            //      snnnnn = -17999 to 18000 
            bool set_heading( std::string data = "00000" ); 
        
            // Page 134 : set the water salinty value
            // format ESnn
            //      nn = 00 to 40
            bool set_salinty( std::string data = "35" );

            // Page 163 : set time per ensemble
            // format TEhh:mm:ss.ff
            //      hh = 00 to 23 hours
            //      mm = 00 to 59 minutes
            //      ss = 00 to 59 seconds
            //      ff = 00 to 99 hundredths of second
            // Default TE00:00:00.00
            //      Default that mean if success collect data will continue start collecting next
            bool time_per_ensemble( std::string data = "00:00:00.00" );

            // Page 164 : set time between Pings warning this have affect to command TE
            // format TPmm:ss.ff
            //      mm = 00 to 59 minutes
            //      ss = 00 to 59 seconds
            //      ff = 00 to 99 hundredths of second
            // Increase if (WP x TP ) > TE
            bool time_between_pings( std::string data = "00:00.05");

            // Page 167 : set pings per ensumble
            // format WPnnnnn
            //      nnnnn = 0 to 16384 pings
            // if WP is zero the DVL dose not collect water profile data
            //    WP will extends if (WP + BP) x TP > TE
            bool ping_per_ensemble( std::string data = "00000" );

            // Page 156 : Choose data stream select
            bool data_stream( std::string data = "6" );
    
            // Page 128 : CK keep parameters
            // Manual have suggestion about send command CR1 first and CK before CS<data stream>
            bool save_paramter();
            
            // Page 129 : CS Starting pinging 
            bool resume();

            bool send_message( std::string* data , unsigned int size_check );

    }; // class connector
 
} // namespace

} // namespace sensor

} // namespace zeabus

#endif // _ZEABUS_SENSOR_DVL_CONNECTOR_HPP__
