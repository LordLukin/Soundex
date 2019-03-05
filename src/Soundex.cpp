#include "Soundex.hpp"
#include <string>
#include <algorithm>

std::string Soundex::returnFirstLetter(std::string word)
{
    std::string result;
    result.push_back(std::toupper(word.at(0)));
    return result;
}
std::string Soundex::removeUnnecesaryLetters(std::string word)
{
    char to_remove[] = "aeiouyhw";

    for(auto letter : to_remove)
    {
        word.erase(std::remove(word.begin()+1, word.end(), letter), word.end());
    }

    return word;
}
