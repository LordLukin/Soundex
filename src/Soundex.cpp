#include "Soundex.hpp"
#include <map>

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

void Soundex::replaceLetterToDigit(std::string& name,
                                   auto findLetterToReplace,
                                   std::string letterToDigit,
                                   char digit,
                                   int i)
{
    if(std::any_of(letterToDigit.begin(),letterToDigit.end(),
                   findLetterToReplace
                   ))
    {
        name[i] = digit;
    }
}

std::string Soundex::replaceToDigits(std::string name)
{

    std::map <std::string, char> codingKey = {{"bfpv",'1'},
                                              {"cgjkqsxz",'2'},
                                              {"dt",'3'},
                                              {"l",'4'},
                                              {"mn",'5'},
                                              {"r",'6'}
                                             };


    if (name.length() ==1) return name + "000";
    for(auto singleCode: codingKey)
    {
        for (int i = 1; i < name.length(); i++)
        {
            auto findLetterToReplace = [&name, i](auto letter){ return name[i] == letter;};
            replaceLetterToDigit(name, findLetterToReplace, singleCode.first,singleCode.second, i);
        }
    }
    if (name.length() == 2) return name + "00";
    if (name.length() == 3) return name + "0";

}

