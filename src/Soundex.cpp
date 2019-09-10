#include "Soundex.hpp"
#include <stdexcept>
#include  <cctype>
#include <algorithm>


std::string Soundex::doSoundex(const std::string input)
{
    if(input.empty())
    {
        throw std::runtime_error("Input is empty");
    }

    if (std::any_of(input.cbegin(), input.cend(), [](auto c){ return !std::isalpha(c); })) {
        throw std::runtime_error("Input contains no alpha value.");
    }

    if(input[1] == 'B' || input[1] == 'F' || input[1] == 'P' || input[1] == 'V')
    {
        return std::string{input[0]} + "100";
    }

    return input + "000";
}
