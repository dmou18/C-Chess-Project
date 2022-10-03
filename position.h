#ifndef Position_H_
#define Position_H_
//#include <string>


class Position {
    public:
    int row;
    int col;
    Position(int r, int c);
    Position(Position &other);
    Position(Position &&other);
    Position &operator=(Position &other);
    Position &operator=(Position &&other);
};


bool operator==(Position, Position);
#endif
