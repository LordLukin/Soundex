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

    return "A000";
}
