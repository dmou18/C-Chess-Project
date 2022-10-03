#ifndef __GAME_H_
#define __GAME_H_

#include <vector>
#include "move.h"
#include "piece.h"
#include "Pieceset.h"
 #include "board.h"

class Game {
    std::vector<Move> pastMoves;
    Pieceset* set;
    bool isWhite;
//    std::vector<Player> players;
//    float w_points;
//    float b_points;

//    std::string checkStatus;
    Board* theBoard = nullptr;
    public:
    ~Game();
    bool isValid(Input input);
    void newGame();
    void setupGame();
    void setupAdd(std::string, Position);
    void setupColor(std::string);
    void setupMinus(Position);
    bool setupValid();
    void update(Input input);
    bool isStatemate();
    bool isChecked();
    bool isCheckmated();
    bool whiteNow();
//`    void set(Piece);
    void clear();
};

#endif

