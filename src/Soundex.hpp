#pragma once
#include <string>
#include <map>

class Soundex
{
    std::map<char, char> mapa;
public:
   std::string soundex(std::string);
   Soundex();

};
