#include "Soundex.hpp"

std::string Soundex::soundex(std::string s)
{
    bool flag_is_one = false;
    std::string tmp(1,s[0]);
    for(size_t i = 1; i < s.size(); i++)
    {
        switch(s.at(i)){
        case 'd': tmp.append("3"); break;
        case 'm': tmp.append("5"); break;
        case 'b':
        case 'f':
        case 'p':
        case 'v':
            if(!flag_is_one)
            {
                flag_is_one = true;
                tmp.append("1");
            }   break;
        }
    }
    return tmp;
}
