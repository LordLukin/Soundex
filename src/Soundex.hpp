#pragma once
#include <string>
#include <map>
#include <set>

class Soundex
{
   std::map<char, char> consonants;
   std::set<char> vowels = {'a','e','i','o','u','y'};
   void removeFirstDuplicate(std::string const& s, std::string &tmp);
   void eraseDubles(size_t i, std::string const & s, std::string & tmp);

public:
   std::string soundex(std::string const &);
   Soundex();
};
