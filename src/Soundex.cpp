#include "Soundex.hpp"

std::string Soundex::soundex(std::string s)
{
    if (s.size() == 1)
        return std::string(1,s[0]);
    std::string tmp(1,s[0]);
    for(size_t i = 1; i < s.size(); i++)
    {
        switch(s.at(i)){
        case 'a':  break;
        case 'd': tmp.append("3"); break;
        }
    }
    return tmp;
}
