#ifndef Piece_H
#define Piece_H
#include <string>
#include <vector>
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
#include "position.h"
#include "Pieceset.h"
#include "Info.h"





class Piece {
    protected:
    std::string colour;
    std::string type;
    bool moved;
    bool alive;
    Position pos;
    Pieceset *set;
    public:
    virtual Info getInfo();
    void setPos(Position);
    void setAlive(bool);
    void setMove(bool);
<<<<<<< HEAD

    virtual std::vector <Position> validpos();
    virtual std::vector <Position> cappos();
    virtual ~Piece() = 0;
=======
    virtual std::vector <Position> validpos()=0;
    virtual std::vector <Position> cappos()=0;
    virtual ~Piece() = 0;
//    virtual bool isimme(); 
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
    Piece (std::string, std::string, bool, bool,  Position, Pieceset*);
    Piece(Piece &other);
};



class Pawn:public Piece {
    bool promoted;
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
    bool imme;
    Piece *newpiece = nullptr;
    public:
    Info getInfo() override;
    bool getPromoted();
    Info getPromotion();
    bool isimme();
    virtual std::vector<Position> validpos() override;
    virtual std::vector<Position> cappos() override;
    void promote(Piece *);
    void unpromote();
    Pawn(std::string, std::string, bool, bool, Position, Pieceset*, bool,bool, Piece *);
    ~Pawn ();
};


class Rook: public Piece {
    public:
    virtual std::vector<Position> validpos() override;
    virtual std::vector<Position> cappos() override;
    bool castling ();
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
    Rook(std::string, std::string, bool, bool, Position, Pieceset *);
};


class King: public Piece {
    public:
    virtual std::vector<Position> validpos() override;
    virtual std::vector<Position> cappos() override;
    bool castling ();
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
    King(std::string, std::string, bool, bool, Position, Pieceset*);

};


class Queen: public Piece {
    public:
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
    virtual std::vector<Position> validpos() override;
    virtual std::vector<Position> cappos() override;
    Queen(std::string, std::string, bool, bool, Position, Pieceset*);
};


class Bishop: public Piece {
    public:
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
    virtual std::vector<Position> validpos() override;
    virtual std::vector<Position> cappos() override;
    Bishop(std::string, std::string, bool, bool, Position, Pieceset*);
};


class Knight: public Piece {
    public:
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
    virtual std::vector<Position> validpos() override;
    virtual std::vector<Position> cappos() override;
    Knight(std::string, std::string, bool, bool, Position, Pieceset*);
};

#endif
