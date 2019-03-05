#pragma once
#include <string>

class Soundex
{
private:
    std::string returnFirstLetter(std::string word);
    std::string removeUnnecesaryLetters(std::string word);
    std::string replaceLettersWithNumbers(std::string word);
    std::string removeDoubleDigits(std::string word);
    void adjustSize(std::string & word);
public:
    std::string convert(std::string word);
};
