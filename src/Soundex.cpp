#include "Soundex.hpp"
#include <stdexcept>
#include  <cctype>
#include <algorithm>
#include <vector>


std::string Soundex::doSoundex(const std::string input)
{
    if(input.empty())
    {
        throw std::runtime_error("Input is empty");
    }

    if (std::any_of(input.cbegin(), input.cend(), [](auto c){ return !std::isalpha(c); })) {
        throw std::runtime_error("Input contains no alpha value.");
    }

    std::string result {input[0]};

    std::vector<char> cypher = {'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'};
    std::vector<char> cypher2 = {'B', 'F', 'P', 'V'};
    for (auto e : input)
    {
        auto it = std::find(cypher.begin(), cypher.end(), e);
        if(it != cypher.end() and e != input.front() ) {
            result += "2";
        }

        it = std::find(cypher2.begin(), cypher2.end(), e);
        if(it != cypher2.end() and e != input.front() ) {
            result += "1";
        }
    }
    int s = result.size();
    for(int i = 0; i < 4-s; i++)
    {
        result+="0";
    }

    return result;
 
    //return input + "000";
}
