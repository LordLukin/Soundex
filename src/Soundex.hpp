#pragma once
#include <string>

class Soundex
{
public:
    std::string returnFirstLetter(std::string word);
    std::string removeUnnecesaryLetters(std::string word);
    std::string replaceLettersWithNumbers(std::string word);
};
