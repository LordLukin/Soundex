#include "Soundex.hpp"
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>

std::string Soundex::doSoundex(const std::string input)
{
    if (input.empty())
    {
        throw std::runtime_error("Input is empty");
    }

    if (std::any_of(input.cbegin(), input.cend(), [](auto c) { return !std::isalpha(c); }))
    {
        throw std::runtime_error("Input contains no alpha value.");
    }

    std::string result{input[0]};

    std::map<char, int> cypher_map{
        {'C', 2},
        {'G', 2},
        {'J', 2},
        {'K', 2},
        {'Q', 2},
        {'S', 2},
        {'X', 2},
        {'Z', 2},
        {'B', 1},
        {'F', 1},
        {'P', 1},
        {'V', 1}};

    for (int i=1;i<input.size();i++) {
        result += std::to_string(cypher_map[input[i]]);
    }

    int s = result.size();
    for (int i = 0; i < 4 - s; i++)
    {
        result += "0";
    }

    return result;

}
