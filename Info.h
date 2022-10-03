#ifndef _Info_H_
#define _Info_H_
#include <string>
#include "position.h"


struct Info{
    std::string colour;
    std::string type;
    bool moved;
    bool alive;
    Position pos;
    Info (std::string colour, std::string type, bool moved, bool alive, Position pos);
};


#endif
