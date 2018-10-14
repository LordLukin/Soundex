#include "Soundex.hpp"

void Soundex::eraseDuplicate(std::string & in, std::string cop)
{
    // auto it = std::adjacent_find (in.begin(), in.end());
    // in.erase(it, 1);
    for(auto x : in)
    {
        auto it = std::adjacent_find(in.begin(), in.end());
        auto dist = it - it.start();
        if(it != in.end() && *it != '0')
            in.erase(it);
    }
    while(in.size() < 4)
        in.append(1, '0');
}

void Soundex::mappElement(std::string & in)
{
    for(int i=1;i<in.size();i++)
    {
        in[i] = mapa.at(in[i]);
    }
    while(in.size() < 4)
    {
        in.append(1, '0');
    }
    std::cout<<in<<std::endl;
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
    std::string cop = in;
    eraseCharacters(in);
    in[0] = toupper(in[0]);
    mappElement(in);
    eraseDuplicate(in, cop);

    return in.substr(0,4);
}
