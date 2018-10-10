#include "Soundex.hpp"

std::string Soundex::soundex(std::string s)
{
    std::string tmp(1,s[0]);
    for(size_t i = 1; i < s.size(); i++)
    {
        switch(s.at(i)){
        case 'd': tmp.append("3"); break;
        case 'm': tmp.append("5"); break;
        }
    }
    return tmp;
}
