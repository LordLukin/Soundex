#include "Soundex.hpp"

std::string Soundex::soundex(std::string s)
{
    std::string tmp(1,s[0]);
    for(size_t i = 1; i < s.size(); i++)
    {
        switch(s.at(i)){
        case 'm': tmp.append("5"); break;
        case 'b':
        case 'f':
        case 'p':
        case 'v':
            tmp.append("1");
            break;
        case 'c':
        case 'g':
        case 'j':
        case 'k':
        case 'q':
        case 's':
        case 'x':
        case 'z':
            tmp.append("2");
            break;
        case 'd': tmp.append("3"); break;

        }
        if(tmp[tmp.size()-1] == tmp[tmp.size()-2])
            tmp.erase(tmp.size()-1, 1);

    }
    return tmp;
}
