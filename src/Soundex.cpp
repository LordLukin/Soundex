#include "Soundex.hpp"

std::string Soundex::removeAEIOUYHW(std::string name)
{
    std::string signs = "aeiouyhw";

    std::string afterRemove;
    name.erase(std::remove_if(name.begin(),
                              name.end(),
                              [&signs](auto s)
    {
        return std::any_of(signs.cbegin(),
                    signs.cend(),
                    [&s](auto sign)
        {return s==sign;});
    })
               ,name.end());
    return name;
}

std::string Soundex::replaceToDigits(std::string name)
{
    std::string string1 = "bfpv";
    if (name.length() ==1) return name + "000";
    if (name.length()==2)
    {
        name[1]='1';
    }
    return name + "00";
}
