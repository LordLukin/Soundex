#pragma once
#include<string>
#include<algorithm>

class Soundex
{
public:
    std::string removeAEIOUYHW(std::string name);
    std::string replaceToDigits(std::string name);
};
