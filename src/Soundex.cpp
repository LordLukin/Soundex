#include "Soundex.hpp"

Soundex::Soundex()
{
    for (auto i : {'b','f','p','v'}) {
        mapa[i] = '1';
    }

    for (auto i : {'c','g','j','k','q','s','x','z'}) {
        mapa[i] = '2';
    }

    for (auto i : {'d','t'}) {
        mapa[i] = '3';
    }

    mapa['l'] = '4';
    mapa['m'] = '5';
    mapa['n'] = '5';
    mapa['r'] = '6';
}
std::string Soundex::soundex(std::string s)
{
    std::string tmp(1,s[0]);
    for(size_t i = 1; i < s.size(); i++)
    {
        if (mapa.find(s.at(i)) != mapa.end())
          tmp.append(1,(mapa[s.at(i)]));

        if(tmp[tmp.size()-1] == tmp[tmp.size()-2])
            tmp.erase(tmp.size()-1, 1);

    }
    if(tmp.size() > 3)
    {
        tmp.erase(4, tmp.size() - 4);
    }
    else
        tmp.append(4 - tmp.size(), '0');
    return tmp;
}
