// FILE         : escape_sequence.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 05

#include    <zeabus/escape_sequence.hpp>

namespace zeabus
{

namespace escape_code
{

    const static std::string normal_red = "\x1B[0;31m";
    const static std::string normal_greem = "\x1B[0;32m";
    const static std::string normal_yellow = "\x1B[0;33m";
    const static std::string normal_blue = "\x1B[0;34m";
    const static std::string normal_margenta = "\x1B[0;35m";
    const static std::string normal_cyan = "\x1B[0;36m";
    const static std::string normal_white = "\x1B[0;37m";

    const static std::string bold_red = "\x1B[1;31m";
    const static std::string bold_greem = "\x1B[1;32m";
    const static std::string bold_yellow = "\x1B[1;33m";
    const static std::string bold_blue = "\x1B[1;34m";
    const static std::string bold_margenta = "\x1B[1;35m";
    const static std::string bold_cyan = "\x1B[0;36m";
    const static std::string bold_white = "\x1B[1;37m";

    void clear_screen()
    {
        std::cout << "\x1B[1J\x1B[H";
    } // void clear_screen

} // namespace escape_code

} // namespace zeabus
