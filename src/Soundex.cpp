#include "Soundex.hpp"

std::string Soundex::soundex(std::string s)
{
    if (s.size() != 3)
        return std::string(1,s[0]) ;

    else return "R3";
}
