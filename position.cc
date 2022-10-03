#include "position.h"



Position::Position(int r, int c):row{r}, col{c} {}

Position::Position(Position &other):row{other.row}, col{other.col} {}

Position::Position(Position &&other) : row{other.row}, col{other.col} {}

Position &Position::operator=(Position &other) {
    if (this == &other) return *this;
    this->row = other.row;
    this->col = other.col;
    return *this;
}


Position &Position::operator=(Position &&other) {
    this->row=other.row;
    this->col=other.col;
    return *this;
}


bool operator==(Position a, Position b) {
        return (a.row == b.row && a.col == b.col);
}


