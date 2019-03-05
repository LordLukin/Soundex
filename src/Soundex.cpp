#include "Soundex.hpp"
#include <string>
#include <algorithm>
#include <map>

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

std::string Soundex::replaceLettersWithNumbers(std:: string word)
{
    //std::vector<std::vector<char>> groups = {"bfpv", "cgjkqsxz", "dt", "l", "mn", "r"};
    std::string result = word;

    std::map<char, char> m = {{'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
                              {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'},
                              {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
                              {'d', '3'}, {'t', '3'},
                              {'l', '4'},
                              {'m', '5'}, {'n', '5'},
                              {'r', '6'}
                             };

    for(auto &letter : result)
    {
        auto it = m.find(letter);
        if(it != m.end())
            letter = it->second;
    }

    return result;
}

std::string Soundex::convert(std::string word)
{
    std::string result = removeUnnecesaryLetters(word);
    result = replaceLettersWithNumbers(result);
    return result;
}
