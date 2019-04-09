// FILE         : escape_code.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 05

#include    <zeabus/escape_code.hpp>

namespace zeabus
{

namespace escape_code
{

    void clear_screen()
    {
        std::cout << "\x1B[1J\x1B[H";
    } // void clear_screen

} // namespace escape_code

} // namespace zeabus
