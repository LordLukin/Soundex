#pragma once
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
class Soundex
{
public:
    std::string decode(std::string in);
private:
    std::map <char, char> mapa =
    {
        std::make_pair('b','1'),
        std::make_pair('f','1'),
        std::make_pair('p','1'),
        std::make_pair('v','1'),
        std::make_pair('c','2'),
        std::make_pair('g','2'),
        std::make_pair('j','2'),
        std::make_pair('k','2'),
        std::make_pair('q','2'),
        std::make_pair('s','2'),
        std::make_pair('x','2'),
        std::make_pair('z','2'),
        std::make_pair('d','3'),
        std::make_pair('l','4'),
        std::make_pair('m','5'),
        std::make_pair('n','5'),
        std::make_pair('r','6'),
    };
    void mappElement(std::string & in);
    void eraseCharacters(std::string & in);
};
