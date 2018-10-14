#include "Soundex.hpp"



void Soundex::mappElement(std::string & in)
{
    if (in.size() == 1)
    {
        in.append(3, '0');
    } else if (in.size() == 3)
    {
        in[1] = mapa.at(in[1]);
        in[2] = mapa.at(in[2]);
        in.append(1, '0');
    }
    else if (in.size() == 4)
    {
        in[1] = mapa.at(in[1]);
        in[2] = mapa.at(in[2]);
        in[3] = mapa.at(in[3]);

    }
    else if (in.size() == 5)
    {
        in[1] = mapa.at(in[1]);
        in[2] = mapa.at(in[2]);
        in[3] = mapa.at(in[3]);
        in[4] = mapa.at(in[4]);

    }
    else
    {
        in[1] = mapa.at(in[1]);
        in.append(2, '0');
    }
}

void Soundex::eraseCharacters(std::string& in)
{
    std::string toErase= "aeiouyhw";
    for (auto s : toErase)
    {
        auto it = in.find_first_of(s);
        while (it != std::string::npos)
        {
            in.erase(it,1);
            it = in.find_first_of(s);
        }
    }
    std::cout<<in.size()<<std::endl;
}

std::string Soundex::decode(std::string in) {
    eraseCharacters(in);
    in[0] = toupper(in[0]);
    mappElement(in);

    return in;
}
