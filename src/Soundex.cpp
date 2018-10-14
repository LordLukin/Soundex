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

void Soundex::replaceLetterToDigit(std::string& name,
                                   auto findLetterToReplace,
                                   std::string letterToDigit,char digit)
{
    if(std::any_of(letterToDigit.begin(),letterToDigit.end(),
                   findLetterToReplace
                   ))
    {
        name[1] = digit;
    }
}

std::string Soundex::replaceToDigits(std::string name)
{
    std::string letterTo_1 = "bfpv";
    std::string letterTo_2 = "cgjkqsxz";
    std::string letterTo_3 = "dt";
    std::string letterTo_4 = "l";
    std::string letterTo_5 = "mn";
    std::string letterTo_6 = "r";

    auto findLetterToReplace = [&name](auto letter){ return name[1] == letter;};
    if (name.length() ==1) return name + "000";
    replaceLetterToDigit(name, findLetterToReplace, letterTo_1, '1');
    replaceLetterToDigit(name, findLetterToReplace, letterTo_2, '2');
    replaceLetterToDigit(name, findLetterToReplace, letterTo_3, '3');
    replaceLetterToDigit(name, findLetterToReplace, letterTo_4, '4');
    replaceLetterToDigit(name, findLetterToReplace, letterTo_5, '5');
    replaceLetterToDigit(name, findLetterToReplace, letterTo_6, '6');
    return name + "00";
}

