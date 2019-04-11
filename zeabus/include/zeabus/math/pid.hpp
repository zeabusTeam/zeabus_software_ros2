// FILE         : pid.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 12

#include    <iostream> // standard library of c++ language

// This is normal PID (Propotional , Integral , Derivation ) calculate
// Not use real time but use time constant to calculate

#ifndef _ZEABUS_MATH_PID_HPP__
#define _ZEABUS_MATH_PID_HPP__

namespace zeabus
{

namespace math
{

    class PID
    {

        public:
            PID( double p = 0 , double i = 0 , double d = 0 );
            
            // function for set 3 constant
            void set_constant( double p , double i , double d );

            // will set offset of first time that will make fast value in first time
            void offset_i( double offset ); 

            // this will set limit result of value but it bound only 'id' term
            void set_limit( double min , double max );
            void set_limit_min( double min );
            void set_limit_max( double max );

            void calculate( double error , double* result );

            void reset_value();

        protected:
            double p_constant;
            double i_constant;
            double d_constant; 

            double max_limit; // bound on positive term
            double min_limit; // bound on negative term
            double sum; // that is result in 'id' term only
                        // result haved return that is p + 'id' value
            double previous_error; // previous error of input on frist time that will zero

    }; //  class PID

} // namespace math

} // namespace zeabus

#endif // _ZEABUS_MATH_PID_HPP__
