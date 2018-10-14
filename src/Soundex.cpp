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
    std::string string2 = "cgjkqsxz";
    if (name.length() ==1) return name + "000";
    if(std::any_of(string1.begin(),string1.end(),
                   [&name](auto letter){ return name[1] == letter;}
                  ))
    {
        name[1] = '1';
    }
    if(std::any_of(string2.begin(),string2.end(),
                   [&name](auto letter){ return name[1] == letter;}
                  ))
    {
        name[1] = '2';
    }
    return name + "00";

}
