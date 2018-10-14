#pragma once
#include<string>
#include<algorithm>

class Soundex
{
     void replaceLetterToDigit(std::string& name,
                               auto findLetterToReplace,
                               std::string letterToDigit,
                               char digit,
                               int i);
public:
    std::string removeAEIOUYHW(std::string name);
    std::string replaceToDigits(std::string name);

};
