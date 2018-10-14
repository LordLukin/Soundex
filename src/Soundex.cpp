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
