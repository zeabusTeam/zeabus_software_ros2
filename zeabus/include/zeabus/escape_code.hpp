// FILE         : escape_sequence.hpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 05

#include    <iostream> // for standard library of c++

// This file will manage about ANSI Escape sequence 
// This escape sequence can use in MISRA C++ 2018 by RULE 2-13-1 REQUIRED
//      DETAIL : Only those escape sequence that are defined in ISO/IEC 14882:2003 shall be use
// That ISO/IEC include \n, \t, \v, \b, \r, \f, \a, \\, \?, \', \", \<Oct Number>, \x<Hex Num>
// Refernece 
//  : http://ascii-table.com/ansi-escape-sequences-vt-100.php
//  : http://ascii-table.com/ansi-escape-sequences.php
//  : https://stackoverflow.com/questions/37774983/clearing-the-screen-by-printing-a-character

namespace zeabus
{

namespace escape_code
{

    void clear_screen();

} // namespace escape_code

} // namespace zeabus
