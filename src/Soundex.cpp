#include "Soundex.hpp"
#include <string>

std::string Soundex::returnFirstLetter(std::string word)
{
    std::string result;
    result.push_back(std::toupper(word.at(0)));
    return result;
}
