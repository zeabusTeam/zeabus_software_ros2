// FILE         : pid.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 12

#include    <zeabus/math/pid.hpp>

namespace zeabus
{

namespace math
{

    PID::PID( double p , double i , double d )
    {
        this->set_constant( p , i , d );
        this->set_offset( 0 );
    } // init function of pid 

    void PID::set_constant( double p , double i , double d )
    {
        this->p_constant = p;
        this->i_constant = i;
        this->d_constant = d;
        this->reset_value();
    } // function set_constant

    void PID::set_limit( double min , double max )
    {
        this->set_limit_min( min );
        this->set_limit_max( max );
    } // function set_limit

    void PID::set_limit_max( double max )
    {
        this->max_limit = max;
    } // function set_limit_max

    void PID::set_limit_min( double min )
    {
        this->min_limit = min;
    } // function set_limit_min

    void PID::set_offset( double offset )
    {
        this->offset = offset;
    } // function set_offset

    void PID::reset_value()
    {
        this->sum = this->offset;
        this->previous_error = 0 ;
    } // function reset_value

    void PID::calculate( double error , double* result )
    {
        this->sum += ( ( this->previous_error + error ) * this->i_constant )
                - ( ( error - this->previous_error ) * this->d_constant );
        if( this->sum > this->max_limit )
        {
            this->sum = this->max_limit;
        } // conndtion 'id' term > max_limit
        else if( this->sum < this->min_limit )
        {
            this->sum = this->min_limit;
        } // condition 'id' term < min_limit
        else
        {
            ; // sum will same value don't bound
        }
        *result = this->sum + ( error * this->p_constant );
        this->previous_error = error; // now is delay unit?
    } 

} // namespace math

} // namespace zeabus
