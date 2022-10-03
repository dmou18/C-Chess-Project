#ifndef __MOVE_H_
#define __MOVE_H_


#include "position.h"
#include <string>

struct Move{
    Position startPos;
    Position endPos;
    std::string color; // color of the moved piece
    std::string type; // Queen: "Queen"; Rook: "Rook"; ...
    std::string captype; // Same as above, adding No Capture: "NC"
    int specialMove; // 0: none; 1: castling; 2: en passant; 3: promotion
};

struct Input {
    Position startPos;
    Position endPos;
    std::string promotion; // "NP" stands for no promotion
};

#endif
