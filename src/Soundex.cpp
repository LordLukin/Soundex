#include "Soundex.hpp"
#include <iostream>

Soundex::Soundex()
{
    for (auto i : {'a','e','i','o','u','y'})
        vowels[i] = true;

    for (auto i : {'b','f','p','v'})
        consonants[i] = '1';

    for (auto i : {'c','g','j','k','q','s','x','z'})
        consonants[i] = '2';

    for (auto i : {'d','t'})
        consonants[i] = '3';

    consonants['l'] = '4';
    consonants['m'] = '5';
    consonants['n'] = '5';
    consonants['r'] = '6';
}
std::string Soundex::soundex(std::string s)
{
    std::string tmp(1,s[0]);
    for(size_t i = 1; i < s.size(); i++)
    {
        if (consonants.find(s.at(i)) != consonants.end())
            tmp.append(1,(consonants[s.at(i)]));

        if(tmp[tmp.size()-1] == tmp[tmp.size()-2])
            if(vowels.find(s.at(i-1)) == vowels.end())
                tmp.erase(tmp.size()-1, 1);


    }
    //std::cout << "turrr jestem";
    auto first_char = std::tolower(s.at(0));
    if(consonants.find(first_char) != consonants.end())
    {

        std::cout << "tu jestem";
        if(tmp.size() > 1 && tmp[1] == consonants[first_char])
        {
            std::cout << "Weszlam/wszedlem do ifa";
            tmp.erase(1, 1);
        }
    }
    if(tmp.size() > 3)
    {
        tmp.erase(4, tmp.size() - 4);
    }
    else
        tmp.append(4 - tmp.size(), '0');
    return tmp;
}
