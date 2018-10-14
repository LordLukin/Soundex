#include "Soundex.hpp"

std::string Soundex::removeAEIOUYHW(std::string name)
{
    std::string signs = "aeiouyhw";

    std::string afterRemove;

    auto findToRemove = [&signs](auto s)
    {
        auto letterIsCompare =[&s](auto sign){return s==sign;};

        return std::any_of(signs.cbegin(),
                           signs.cend(),
                           letterIsCompare);
    };
    name.erase(std::remove_if(name.begin(),
                              name.end(),
                              findToRemove)
               ,name.end());
    return name;
}

std::string Soundex::replaceToDigits(std::string name)
{
    std::string letterTo_1 = "bfpv";
    std::string letterTo_2 = "cgjkqsxz";
    if (name.length() ==1) return name + "000";
    if(std::any_of(letterTo_1.begin(),letterTo_1.end(),
                   [&name](auto letter){ return name[1] == letter;}
                   ))
    {
        name[1] = '1';
    }
    if(std::any_of(letterTo_2.begin(),letterTo_2.end(),
                   [&name](auto letter){ return name[1] == letter;}
                   ))
    {
        name[1] = '2';
    }
    return name + "00";
}

