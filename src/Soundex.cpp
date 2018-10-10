#include "Soundex.hpp"

std::string Soundex::soundex(std::string s)
{
    bool flag[6] = {};
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
            if(!flag[0])
            {
                flag[0] = true;
                tmp.append("1");
            }   break;
        case 'c':
        case 'g':
        case 'j':
        case 'k':
        case 'q':
        case 's':
        case 'x':
        case 'z':
            if(!flag[1])
            {
                flag[1] = true;
                tmp.append("2");
            }   break;

        }

    }
    return tmp;
}
