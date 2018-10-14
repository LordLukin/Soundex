#include "Soundex.hpp"
#include <map>
#include <cctype>

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
        for (int i = 0; i < name.length(); i++)
        {
            auto findLetterToReplace = [&name, i](auto letter){ return name[i] == letter;};
            replaceLetterToDigit(name,
                                 findLetterToReplace,
                                 singleCode.first,
                                 singleCode.second,
                                 i);
        }
    }
    for(int i =name.length(); i<4;i++)
        name.push_back('0');
    return name;
}
std::string Soundex::removeDoubleDigit(std::string name)
{
    std::string name_ = name;
    name_[0] = std::tolower(name_[0]);
    name_ = replaceToDigits(name_);
    auto doubleDigit = std::adjacent_find(name_.begin(), name_.end());
    while(doubleDigit != name_.end())
    {
        doubleDigit = std::adjacent_find(name_.begin(), name_.end());
        if(doubleDigit != name_.end())
            name_.erase(doubleDigit);
    }
    for(int i=1; i<name_.length()-1;i++)
    {
        if(name_[i]=='w' || name_[i]=='h')
        {
            if(name_[i-1]==name_[i+1])
            {
                name_.erase(i-1,1);
            }
        }
    }
    name_[0] = name[0];
    name_ = removeAEIOUYHW(name_);
    for(int i =name_.length(); i<4;i++)
        name_.push_back('0');
    name_.erase(4);
    return name_;
}

