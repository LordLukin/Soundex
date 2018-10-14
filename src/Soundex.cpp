#include "Soundex.hpp"


std::string Soundex::decode(std::string in) {

     in[0] = toupper(in[0]);
     if (in.size() == 1)
     {
             in.append(3, '0');
     } else if (in.size() == 3)
     {
         in[1] = mapa.at(in[1]);
         in[2] = mapa.at(in[2]);
         in.append(1, '0');
     }
     else
     {
        in[1] = mapa.at(in[1]);
        in.append(2, '0');
     }

     return in;
}
