#include "Soundex.hpp"
#include <iostream>
#include <algorithm>

Soundex::Soundex()
{


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
void Soundex::eraseDubles(size_t i, std::string const & s, std::string & tmp)
{
    if(tmp[tmp.size()-1] == tmp[tmp.size()-2])
        if(vowels.find(s.at(i-1)) == vowels.end())
            tmp.erase(tmp.size()-1, 1);
}

void Soundex::removeFirstDuplicate(std::string const& s, std::string &tmp)
{
    auto first_char = std::tolower(s.at(0));
    if(consonants.find(first_char) != consonants.end())
        if(tmp.size() > 1 && tmp.at(1) == consonants.at(first_char))
            tmp.erase(1, 1);
}

std::string Soundex::soundex(std::string const & s)
{
    std::string result(1,s.at(0));
    for(size_t i = 1; i < s.size(); i++)
    {
        if (consonants.find(s.at(i)) != consonants.end())
            result.append(1,(consonants.at(s.at(i))));

        eraseDubles(i, s, result);
    }
    removeFirstDuplicate(s, result);

    if(result.size() > 3)
        result.erase(4, result.size() - 4);

    else
        result.append(4 - result.size(), '0');
    return result;
}
