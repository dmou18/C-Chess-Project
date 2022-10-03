#include "piece.h"
#include <vector>
<<<<<<< HEAD

#include "position.h"
#include "Pieceset.h"
#include <memory>
=======
#include "position.h"
#include "Pieceset.h"
#include <iostream>
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
using namespace std;

// Ctor for Piece

Piece::Piece (string colour, string type, bool moved, bool alive, Position pos, Pieceset* set): \
        colour{colour}, type{type}, moved{moved}, alive{alive}, pos{pos}, set{set} {}

Piece::Piece(Piece &other) : colour{other.colour}, type{other.type}, moved{other.moved}, \
        alive{other.alive}, pos{other.pos}, set{other.set} {}


Pawn::Pawn(string colour, string type, bool moved, bool alive, Position pos, \
        Pieceset *set, bool promoted, bool imme, Piece *newpiece = nullptr):\
     Piece{colour, type, moved, alive, pos, set}, promoted{promoted}, imme{imme}, newpiece{newpiece} {}
     
King::King(string colour, string type, bool moved, bool alive, Position pos, Pieceset *set): \
        Piece{colour, type, moved, alive, pos, set} {}

Bishop::Bishop(string colour, string type, bool moved, bool alive, Position pos, Pieceset *set): \
        Piece{colour, type, moved, alive, pos, set} {}



Rook::Rook(string colour, string type, bool moved, bool alive, Position pos, Pieceset *set): \
        Piece{colour, type, moved, alive, pos, set} {}


Knight::Knight(string colour, string type, bool moved, bool alive, Position pos, Pieceset *set): \
        Piece{colour, type, moved, alive, pos, set} {}


Queen::Queen(string colour, string type, bool moved, bool alive, Position pos, Pieceset *set): \
        Piece{colour, type, moved, alive, pos, set} {}


// dtors for classes

Pawn::~Pawn() {
    delete newpiece;
}

Piece::~Piece() {};


// setPos() changes the piece pos and moved condition
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
void Piece::setPos(Position newpos) {
    pos = newpos;
    moved = true;
}


// setAlive changes the alive condition of a piece
void Piece::setAlive(bool c) {
    alive = c;
}


// setMove changes the moved condition of a piece
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
void Piece::setMove(bool c) {
    moved = c;
}



// getInfo() get the information about the piece

<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
Info Piece::getInfo() {
    return Info {colour, type, moved, alive, pos};
}


Info Pawn::getInfo() {
    return getPromoted() ? newpiece->getInfo() : Piece::getInfo();
}

bool Pawn::isimme() {
    return imme;
}

/*bool Piece::ismme() {
    return false;
}*/


////////////////////////////////////////////////////////////////////////
// Some helper functions

// inbound check if the position is board
bool inbound(Position pos) {
    int row = pos.row;
<<<<<<< HEAD

    int col = pos.col;
    return (1 <= row && row <= 8 && col <= 1 && col <=8);
}



=======
    int col = pos.col;
    return (1 <= row && row <= 8 && col >=  1 && col <=8);
}


>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e


// foccupied check if the pos is occupied by a piece with the same colour
bool foccupied (Pieceset *set, Position pos, string colour) {
//    Position pos {piece.getInfo().pos.row, piece.getInfo().pos.col};
    vector <Piece *> sset = set->theset;
    int len = sset.size();
    for (int i = 0; i < len; ++ i) {
       if (sset[i]->getInfo().alive && sset[i]->getInfo().pos == pos && sset[i]->getInfo().colour == colour) {
           return true;
       }
    }
    return false;
}


<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
// eoccupied check if pos if occupied by a piece with opposite colour
bool eoccupied (Pieceset *set, Position pos, string colour) {
    vector <Piece *> sset = set->theset;
    int len = sset.size();
    for (int i = 0; i < len; ++ i) {
       if (sset[i]->getInfo().alive && sset[i]->getInfo().pos == pos && sset[i]->getInfo().colour != colour) {
           return true;
       }
    }
    return false;
}





<<<<<<< HEAD

// occupied check if pos is occupied
bool occupied (Pieceset *set, Position pos) {
    return (foccupied(set, pos, "b") || eoccupied(set, pos, "w"));
=======
// occupied check if pos is occupied
bool occupied (Pieceset *set, Position pos) {
    return (foccupied(set, pos, "b") || eoccupied(set, pos, "b"));
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
}

/////////////////////////////////////////////////////////////////////////////////

bool Pawn::getPromoted() {
    return promoted;
}

void Pawn::promote(Piece *piece) {
    newpiece = piece;
    if (!newpiece) promoted = true;
}

void Pawn::unpromote() {
    delete newpiece;
    newpiece = nullptr;
    promoted = false;
}


// 
vector<Position> Pawn::validpos() {
    vector <Position> v;
    if (promoted) {
        return newpiece->validpos();
    }
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
    Position up = Position {pos.row + 1, pos.col};
    Position uptwo = Position {pos.row + 2, pos.col};
    Position upleft = Position {pos.row + 1, pos.col - 1};
    Position upright = Position {pos.row + 1, pos.col + 1};
    Position left = Position {pos.row, pos.col - 1};
    Position right = Position {pos.row, pos.col + 1};
    Position down = Position {pos.row - 1, pos.col};
    Position downtwo = Position {pos.row - 2, pos.col};
    Position downleft = Position {pos.row - 1, pos.col - 1};
    Position downright = Position {pos.row - 1, pos.col + 1};
<<<<<<< HEAD
    if (!moved) {
             int len = set->theset.size();
        vector <Position> v;
        if (colour == "w") {
         for (int i = 0; i < len; ++ i) {
            if (foccupied(set, up, "w")) {
                return v;
            }
            if (eoccupied(set, up, "w")) {

                v.emplace_back(up);
                return v;
            }
         }
         v.emplace_back(up);
         for (int i = 0; i < len; ++i) {

            if (foccupied(set, uptwo, "w")) {
                return v;
            }
            if (eoccupied(set, uptwo, "w")) {
                v.emplace_back(uptwo);
                return v;
            }
         }
        }

        if (colour == "b") {
            for (int i = 0; i < len; ++ i) {
            if (foccupied(set, down, "b")) {
                return v;
            }
            if (eoccupied(set, down, "b")) {

                v.emplace_back(down);
                return v;
            }
         }
         v.emplace_back(down);
         for (int i = 0; i < len; ++i) {
            if (foccupied(set, downtwo, "b")) {
                return v;
            }
            if (eoccupied(set, downtwo, "b")) {

                v.emplace_back(downtwo);
                return v;
            }
         }
        }
    }
=======

>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e

    if (colour == "w") {
/*       cout << "the piece is white" << endl;
        if (!getInfo().moved) {
            cout << "move condition: not moved" <<endl;
        }
        cout << "Piece Position: row: " << up.row << " col: " << up.col <<endl;
        if (!inbound(up)) cout << "up is not inbound" << endl;
        if (!inbound(uptwo)) cout << "uptwo is not inbound" << endl;
        if (!occupied(set, up)) cout << "up is not occupied" << endl;
        if (!occupied(set, uptwo)) cout << "uptwo is not occupied" << endl;
*/        
        if (!moved && inbound(uptwo) && !occupied(set, up) && !occupied(set, uptwo)) {
//            cout << "white uptwo valid " << endl;
            v.emplace_back(uptwo);
        }
        if (inbound(up) && !occupied(set, up))  {
                v.emplace_back(up);
        }
        if (inbound(upleft) && eoccupied(set, upleft, "w")) {
            v.emplace_back(upleft);
        } 
<<<<<<< HEAD
        if (inbound(left) && eoccupied(set, left, "w")) {

=======
        if (inbound(upleft) && eoccupied(set, left, "w")) {
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
            int len = set->theset.size();
            vector <Piece *> sset = set->theset;
            for (int i = 0; i < len; ++i) {
                if (sset[i]->getInfo().alive && sset[i]->getInfo().pos == left 
<<<<<<< HEAD
                        && sset[i]->getInfo().type == "Pawn" && dynamic_cast<Pawn *>(sset[i])->isimme()) {
=======
                        && sset[i]->getInfo().type == "Pawn" && sset[i]->getInfo().colour == "b" && dynamic_cast<Pawn *>(sset[i])->isimme()) {
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
                    v.emplace_back(upleft);
                    break;
                }
            }
        }
        if (inbound(upright) && eoccupied(set, upright, "w")) {
            v.emplace_back(upright);
        } 
<<<<<<< HEAD
        if (inbound(right) && eoccupied(set, right, "w")) {

=======
        if (inbound(upright) && eoccupied(set, right, "w")) {
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
            int len = set->theset.size();
            vector <Piece *>sset = set->theset;
            for (int i = 0; i < len; ++i) {
                if (sset[i]->getInfo().alive && sset[i]->getInfo().pos == right && \
<<<<<<< HEAD
                        sset[i]->getInfo().type == "Pawn" && dynamic_cast<Pawn*>(sset[i])->isimme()) {
=======
                        sset[i]->getInfo().type == "Pawn" && sset[i]->getInfo().colour == "b" && dynamic_cast<Pawn *>(sset[i])->isimme()) {
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
                    v.emplace_back(upright);
                    break;
                }
            }
        }
        return v;
    }


    if (colour == "b") {
        if (!moved && inbound(downtwo) && !occupied(set, down) && !occupied(set,downtwo)) {
            v.emplace_back(downtwo);
        }
        if (inbound(down) && !occupied(set, down))  {
                v.emplace_back(down);
        }
        if (inbound(downleft) && eoccupied(set, downleft, "b")) {
            v.emplace_back(down);
        } 
        if (inbound(left) && eoccupied(set, left, "b")) {
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
            int len = set->theset.size();
            vector <Piece *>sset = set->theset; 
            for (int i = 0; i < len; ++i) {
                if (sset[i]->getInfo().alive && sset[i]->getInfo().pos == left && \
                            sset[i]->getInfo().type == "Pawn" && dynamic_cast<Pawn *>(sset[i])->isimme()) {
                    v.emplace_back(downleft);
                    break;
                }
            }
        }

        if (inbound(downright) && eoccupied(set, downright, "b")) {
            v.emplace_back(downright);
        } 
        if (inbound(right) && eoccupied(set, right, "b")) {
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
            int len = set->theset.size();
            vector <Piece *>sset = set->theset;
            for (int i = 0; i < len; ++i) {
                if (sset[i]->getInfo().alive && sset[i]->getInfo().pos == right && \
                        sset[i]->getInfo().type == "Pawn" && dynamic_cast<Pawn *>(sset[i])->isimme()) {
                    v.emplace_back(downright);
                    break;
                }
            }
        }

    }
    return v;
}

    



vector <Position> Pawn::cappos() {
    vector <Position> v = this->validpos();
    vector <Position> cv;
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        if (eoccupied(set, v[i], colour)) {
                cv.emplace_back(v[i]);
        }
    }
    return cv;
}



/////////////////////////////////////////////////
// methods for Rook
//

vector <Position> Rook::validpos() {
    vector <Position> v;
    int r = pos.row;
    int c = pos.col;
<<<<<<< HEAD

=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
    for (int i = r + 1; inbound(Position {r, c}); ++i) {
            if (foccupied(set, Position{i, c}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {i, c});
                break;
            }
            v.emplace_back(Position {i, c});
    }

    for (int i = r - 1; inbound(Position {i, c}); --i) {
<<<<<<< HEAD
            if (foccupied(set, Position{i, c}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {i, c});
                break;
            }
            v.emplace_back(Position {i, c});
    }

    for (int i = c - 1; inbound(Position {r, i}); --i) {
            if (foccupied(set, Position{r, i}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {r, i});
                break;
            }
            v.emplace_back(Position {r, i});
    }

    for (int i = c + 1; inbound(Position {r, i}); ++i) {
            if (foccupied(set, Position{r, i}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {r, i});
                break;
            }
            v.emplace_back(Position {r, i});
    }

    return v;
}



vector <Position> Rook::cappos() {
    vector <Position> v = this->validpos();
    vector <Position> cv;
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        if (eoccupied(set, v[i], colour)) {
                cv.emplace_back(v[i]);
        }
    }
    return cv;
}



////////////////////////////////////////////////////////////
// methods for Bishop

vector<Position> Bishop::validpos() {
    vector <Position> v;
    int r = pos.row;
    int c = pos.col;
    for (int i = r + 1, j = c + 1; inbound(Position {i, j}); ++i, ++j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
        v.emplace_back(checkpos);
    }

    for (int i = r + 1, j = c - 1; inbound(Position {i, j}); ++i, --j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
        v.emplace_back(checkpos);
    }


    for (int i = r - 1, j = c - 1; inbound(Position {i, j}); --i, --j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
        v.emplace_back(checkpos);
    }

    for (int i = r - 1, j = c + 1; inbound(Position {i, j}); --i, ++j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
        v.emplace_back(checkpos);
    }

    return v;
}





vector <Position> Bishop::cappos() {
    vector <Position> v = this->validpos();
    vector <Position> cv;
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        if (eoccupied(set, v[i], colour)) {
                cv.emplace_back(v[i]);
        }
    }
    return cv;
}



//////////////////////////////////////////////////////////
// methods for Queen 


vector<Position> Queen::validpos() {
    vector <Position> v;
    int r = pos.row;
    int c = pos.col;
    for (int i = r + 1, j = c + 1; inbound(Position {i, j}); ++i, ++j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
            v.emplace_back(checkpos);
    }

    for (int i = r + 1, j = c - 1; inbound(Position {i, j}); ++i, --j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
            v.emplace_back(checkpos);
    }


    for (int i = r - 1, j = c - 1; inbound(Position {i, j}); --i, --j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
             v.emplace_back(checkpos);
    }

    for (int i = r - 1, j = c + 1; inbound(Position {i, j}); --i, ++j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
             v.emplace_back(checkpos);
    }

    for (int i = r + 1; inbound(Position {i, c}); ++i) {
            if (foccupied(set, Position{i, c}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {i, c});
                break;
            }

            v.emplace_back(Position {i, c});
    }

    for (int i = r - 1; inbound(Position {i, c}); --i) {
=======
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
            if (foccupied(set, Position{i, c}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {i, c});
                break;
            }
            v.emplace_back(Position {i, c});
    }

    for (int i = c - 1; inbound(Position {r, i}); --i) {
            if (foccupied(set, Position{r, i}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {r, i});
                break;
            }
            v.emplace_back(Position {r, i});
    }

    for (int i = c + 1; inbound(Position {r, i}); ++i) {
            if (foccupied(set, Position{r, i}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {r, i});
                break;
            }
            v.emplace_back(Position {r, i});
    }

    return v;
}



<<<<<<< HEAD
=======
vector <Position> Rook::cappos() {
    vector <Position> v = this->validpos();
    vector <Position> cv;
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        if (eoccupied(set, v[i], colour)) {
                cv.emplace_back(v[i]);
        }
    }
    return cv;
}



////////////////////////////////////////////////////////////
// methods for Bishop

vector<Position> Bishop::validpos() {
    vector <Position> v;
    int r = pos.row;
    int c = pos.col;
    for (int i = r + 1, j = c + 1; inbound(Position {i, j}); ++i, ++j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
        v.emplace_back(checkpos);
    }

    for (int i = r + 1, j = c - 1; inbound(Position {i, j}); ++i, --j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
        v.emplace_back(checkpos);
    }


    for (int i = r - 1, j = c - 1; inbound(Position {i, j}); --i, --j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
        v.emplace_back(checkpos);
    }

    for (int i = r - 1, j = c + 1; inbound(Position {i, j}); --i, ++j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
        v.emplace_back(checkpos);
    }

    return v;
}





vector <Position> Bishop::cappos() {
    vector <Position> v = this->validpos();
    vector <Position> cv;
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        if (eoccupied(set, v[i], colour)) {
                cv.emplace_back(v[i]);
        }
    }
    return cv;
}



//////////////////////////////////////////////////////////
// methods for Queen 


vector<Position> Queen::validpos() {
    vector <Position> v;
    int r = pos.row;
    int c = pos.col;
    for (int i = r + 1, j = c + 1; inbound(Position {i, j}); ++i, ++j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
            v.emplace_back(checkpos);
    }

    for (int i = r + 1, j = c - 1; inbound(Position {i, j}); ++i, --j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
            v.emplace_back(checkpos);
    }


    for (int i = r - 1, j = c - 1; inbound(Position {i, j}); --i, --j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
             v.emplace_back(checkpos);
    }

    for (int i = r - 1, j = c + 1; inbound(Position {i, j}); --i, ++j) {
        Position checkpos = Position{i, j};
        if (foccupied(set, checkpos, colour)) {
            break;
        } 
        else if (eoccupied(set, checkpos, colour)) {
            v.emplace_back(checkpos);
            break;
        }
             v.emplace_back(checkpos);
    }

    for (int i = r + 1; inbound(Position {i, c}); ++i) {
            if (foccupied(set, Position{i, c}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {i, c});
                break;
            }
            v.emplace_back(Position {i, c});
    }

    for (int i = r - 1; inbound(Position {i, c}); --i) {
            if (foccupied(set, Position{i, c}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {i, c});
                break;
            }
            v.emplace_back(Position {i, c});
    }

    for (int i = c - 1; inbound(Position {r, i}); --i) {
            if (foccupied(set, Position{r, i}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {r, i});
                break;
            }
            v.emplace_back(Position {r, i});
    }

    for (int i = c + 1; inbound(Position {r, i}); ++i) {
            if (foccupied(set, Position{r, i}, colour)) {
                break;
            }
            else if (eoccupied(set, Position{i, c}, colour)) {
                v.emplace_back(Position {r, i});
                break;
            }
            v.emplace_back(Position {r, i});
    }

    return v;
}



>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
vector <Position> Queen::cappos() {
    vector <Position> v = this->validpos();
    vector <Position> cv;
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        if (eoccupied(set, v[i], colour)) {
                cv.emplace_back(v[i]);
        }
    }
    return cv;
}


/////////////////////////////////////////////////////////////////
// methods for Knight

vector<Position> Knight::validpos() {
    vector<Position> v;
    int r = pos.row;
    int c = pos.col;
    if (inbound(Position {r - 2, c - 1}) && !foccupied(set, Position{r-2, c-1}, colour)) {
        v.emplace_back(Position{r-2, c -1});
    }
    if (inbound(Position {r - 2, c + 1}) && !foccupied(set, Position{r-2, c+1},colour)) {
        v.emplace_back(Position{r-2, c+1});
    }
    if (inbound(Position {r + 2, c - 1}) && !foccupied(set, Position{r+2, c-1},colour)) {
        v.emplace_back(Position{r+2, c-1});
    }
    if (inbound(Position {r + 2, c + 1}) && !foccupied(set, Position{r+2, c+1},colour)) {
        v.emplace_back(Position{r+2, c+1});
    }
    if (inbound(Position {r-1, c-2}) && !foccupied(set, Position{r-1, c-2},colour)) {
        v.emplace_back(Position{r-1, c-2});
    }
    if (inbound(Position {r-1, c+2}) && !foccupied(set, Position{r-1, c+2},colour)) {
        v.emplace_back(Position{r-1, c+2});
    }
    if (inbound(Position {r+1, c-2}) && !foccupied(set, Position{r+1, c-2},colour)) {
        v.emplace_back(Position{r+1, c-2});
    }
    if (inbound(Position {r+1, c+2}) && !foccupied(set, Position{r+1, c+2},colour)) {
        v.emplace_back(Position{r+1, c+2});
    }
    return v;
}



vector <Position> Knight::cappos() {
    vector <Position> v = this->validpos();
    vector <Position> cv;
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        if (eoccupied(set, v[i], colour)) {
                cv.emplace_back(v[i]);
        }
    }
    return cv;
}


////////////////////////////////////////////////////
// methods for King


vector<Position> dangerpos(Pieceset *set, string c) {
    vector <Position> v;
    vector <Piece *> sset = set->theset;
    for (auto x : sset) {
        if (!x->getInfo().alive) continue;
        if (x->getInfo().colour != c) {
            if (x->getInfo().type != "King" ) {
                vector <Position> temp = x->validpos();
                v.insert(v.end(), temp.begin(), temp.end());
            }
            else {
                Position up = Position {x->getInfo().pos.row + 1, x->getInfo().pos.col};
                Position upleft = Position {x->getInfo().pos.row + 1, x->getInfo().pos.col - 1};
                Position upright = Position {x->getInfo().pos.row + 1, x->getInfo().pos.col + 1};
                Position left = Position {x->getInfo().pos.row, x->getInfo().pos.col - 1};
                Position right = Position {x->getInfo().pos.row, x->getInfo().pos.col + 1};
                Position down = Position {x->getInfo().pos.row - 1, x->getInfo().pos.col};
                Position downleft = Position {x->getInfo().pos.row - 1, x->getInfo().pos.col - 1};
                Position downright = Position {x->getInfo().pos.row - 1, x->getInfo().pos.col + 1};
                if (inbound(up)) {
                    v.emplace_back(up);
                }
                if (inbound(upleft)) {
                    v.emplace_back(upleft);
                }
                if (inbound(upright)) {
                    v.emplace_back(upright);
                }
                if (inbound(left)) {
                    v.emplace_back(left);
                }
                if (inbound(right)) {
                    v.emplace_back(right);
                }
                if (inbound(down)) {
                    v.emplace_back(down);
                }
                if (inbound(downleft)) {
                    v.emplace_back(downleft);
                }
                if (inbound(downright)) {
                    v.emplace_back(downright);
                }
            }
        }
    }
    return v;
}


// inposset check if pos is in the posset
bool inposset(vector<Position> posset, Position pos) {
    for (auto x : posset) {
        if (pos == x) {
            return true;
        }
    }
    return false;
}



vector<Position> King::validpos() {
    vector<Position> v;
    Position up = Position {pos.row + 1, pos.col};
    Position upleft = Position {pos.row + 1, pos.col - 1};
    Position upright = Position {pos.row + 1, pos.col + 1};
    Position left = Position {pos.row, pos.col - 1};
    Position lefttwo = Position {pos.row, pos.col - 2};
    Position leftthree = Position{pos.row, pos.col - 3};
    Position right = Position {pos.row, pos.col + 1};
    Position righttwo = Position {pos.row, pos.col + 2};
    Position rightthree = Position {pos.row, pos.col + 3};
    Position down = Position {pos.row - 1, pos.col};
    Position downleft = Position {pos.row - 1, pos.col - 1};
    Position downright = Position {pos.row - 1, pos.col + 1};
    if (inbound(up) && !foccupied(set, up, colour) && !inposset(dangerpos(set, colour), up)) {
            v.emplace_back(up);
    }
    if (inbound(upleft) && !foccupied(set, upleft, colour)&& !inposset(dangerpos(set, colour), upleft)) {
            v.emplace_back(upleft);
    }
    if (inbound(upright) && !foccupied(set, upright, colour) && !inposset(dangerpos(set, colour), upright)) {
            v.emplace_back(upright);
    }
    if (inbound(left) && !foccupied(set, left, colour) && !inposset(dangerpos(set, colour), left)) {
            v.emplace_back(left);
    }
    if (inbound(right) && !foccupied(set, right, colour) && !inposset(dangerpos(set, colour), right)) {
            v.emplace_back(right);
    }
    if (inbound(down) && !foccupied(set, down, colour) && !inposset(dangerpos(set, colour), down)) {
            v.emplace_back(down);
    }
    if (inbound(downleft) && !foccupied(set, downleft, colour) && !inposset(dangerpos(set, colour), downleft)) {
            v.emplace_back(downleft);
    }
    if (inbound(downright) && !foccupied(set, downright, colour) && !inposset(dangerpos(set, colour), downright)) {
            v.emplace_back(downright);
    }

    if (!moved) {
        if (!occupied(set, left) && !inposset(dangerpos(set, colour), left) && !occupied(set, lefttwo) && \
                !inposset(dangerpos(set, colour), lefttwo) && !occupied(set, leftthree)) {
            for (auto y : set->theset) {
                if (y->getInfo().alive && y->getInfo().colour == colour && y->getInfo().type == "Rook" && \
                        !y->getInfo().moved && y->getInfo().pos.col < pos.col) {
                    v.emplace_back(y->getInfo().pos);
                }
                break;
            }
        }
        if (!occupied(set, right) && !inposset(dangerpos(set, colour), right) && !occupied(set, righttwo) && \
                !inposset(dangerpos(set, colour), righttwo) && !occupied(set, rightthree)) {
            for (auto y : set->theset) {
                if (y->getInfo().alive && y->getInfo().colour == colour && y->getInfo().type == "Rook" && \
                        !y->getInfo().moved && y->getInfo().pos.col > pos.col) {
                    v.emplace_back(y->getInfo().pos);
                }
                break;
            }
        }
    }
    return v;
}


vector <Position> King::cappos() {
    vector <Position> v = this->validpos();
    vector <Position> cv;
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        if (eoccupied(set, v[i], colour)) {
                cv.emplace_back(v[i]);
        }
    }
    return cv;
}


