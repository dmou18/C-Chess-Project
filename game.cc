#include "game.h"
#include <string>
#include <vector>
using namespace std;


Game::~Game() {
    if (!theBoard) {
        delete theBoard;
    }
    delete set;
}

void Game::setupGame() {
    delete set;
    delete theBoard;
    isWhite = true;
    Pieceset* set  = new Pieceset;
    theBoard = new Board;
    theBoard->create();
}

bool Game::whiteNow() {
    return isWhite;
}

void Game::setupAdd(string type, Position pos) {
    string cur_color;
    if (isWhite) cur_color = "w";
    else cur_color = "b";
    int length = set->theset.size();
    for (int i = 0; i < length; ++i) {
        if (set->theset[i]->getInfo().alive && set->theset[i]->getInfo().pos == pos) {
            set->theset.erase(set->theset.begin() + i);
            break;
        }
    }
    if (type == "K") {
        for (auto p : set->theset) {
            if (p->getInfo().type == "King" && p->getInfo().colour == cur_color && p->getInfo().alive) {
                cout << "King already exists!" << endl;
                return;
            }
        }
        set->theset.emplace_back(new King{cur_color, "King", false, true, pos, set});
    }
    else if (type == "Q") {
        set->theset.emplace_back(new Queen{cur_color, "Queen", false, true, pos, set});
    }
    else if (type == "R") {
        set->theset.emplace_back(new Rook{cur_color, "Rook", false, true, pos, set});
    }
    else if (type == "N") {
        set->theset.emplace_back(new Knight{cur_color, "Queen", false, true, pos, set});
    }
    else if (type == "B") {
        set->theset.emplace_back(new Bishop{cur_color, "Bishop", false, true, pos, set});
    }
    else if (type == "P") {
        if (isWhite && pos.row == 8) {
            cout << "white pawn in the last row!" << endl;
            return;
        }
        else if (!isWhite && pos.row == 1) {
            cout << "black pawn in the first row!" << endl;
            return;
        }
        set->theset.emplace_back(new Pawn{cur_color, "Pawn", false, true, pos, set, false, false, nullptr});
    }
}

void Game::setupMinus(Position pos) {
    int length = set->theset.size();
    for (int i = 0; i < length; ++i) {
        if (set->theset[i]->getInfo().alive && set->theset[i]->getInfo().pos == pos) {
            set->theset.erase(set->theset.begin() + i);
            break;
        }
    }
}

void Game::setupColor(string color) {
    if (color == "w") isWhite = true;
    else if (color == "b") isWhite = false;
}

bool Game::setupValid() {
    bool temp = isWhite;
    if (isChecked()) {
        cout<< "not valid setup!" << endl;
        isWhite = temp;
        return false;
    }
    isWhite = !isWhite;
    if (isChecked()) {
        cout << "not valid setup!" <<endl;
        isWhite = temp;
        return false;
    }
    isWhite = temp;
    return true;
}

void Game::newGame() {
    cout << "creating new game" << endl;
    if (!set) { // there exists an old gamei
        delete set;
    }
    if (!theBoard) {
        delete theBoard;
    }
    isWhite = true;
        //... field



    while (pastMoves.size() > 0) {
            pastMoves.pop_back();
    }
    

    set = new Pieceset;
//    players[0] = player1;
//    players[1] = player2;
    theBoard = new Board;
    for (int i = 1; i <= 8; ++i) {
        set->theset.emplace_back(new Pawn{"b", "Pawn", false, true, Position{7, i}, set, false, false, nullptr});
        set->theset.emplace_back(new Pawn{"w", "Pawn", false, true, Position{2, i}, set, false, false, nullptr});
    }
    set->theset.emplace_back(new Rook{"b", "Rook", false, true, Position{8, 1}, set});
    set->theset.emplace_back(new Rook{"b", "Rook", false, true, Position{8, 8}, set});
    set->theset.emplace_back(new Rook{"w", "Rook", false, true, Position{1, 1}, set});
    set->theset.emplace_back(new Rook{"w", "Rook", false, true, Position{1, 8}, set});
    set->theset.emplace_back(new Knight{"b", "Knight", false, true, Position{8, 2}, set});
    set->theset.emplace_back(new Knight{"b", "Knight", false, true, Position{8, 7}, set});
    set->theset.emplace_back(new Knight{"w", "Knight", false, true, Position{1, 2}, set});
    set->theset.emplace_back(new Knight{"w", "Knight", false, true, Position{1, 7}, set});
    set->theset.emplace_back(new Bishop{"b", "Bishop", false, true, Position{8, 3}, set});
    set->theset.emplace_back(new Bishop{"b", "Bishop", false, true, Position{8, 6}, set});
    set->theset.emplace_back(new Bishop{"w", "Bishop", false, true, Position{1, 3}, set});
    set->theset.emplace_back(new Bishop{"w", "Bishop", false, true, Position{1, 6}, set});
    set->theset.emplace_back(new Queen{"b", "Queen", false, true, Position{8, 4}, set});
    set->theset.emplace_back(new King{"b", "King", false, true, Position{8, 5}, set});
    set->theset.emplace_back(new Queen{"w", "Queen", false, true, Position{1, 4}, set});
    set->theset.emplace_back(new King{"w", "King", false, true, Position{1, 5}, set});
    theBoard->create();
    cout << "set size: " << set->theset.size() << endl;
}


bool Game::isValid(Input input) {
    string cur_color;
    if (isWhite) cur_color = "w";
    else cur_color = "b";
    cout << cur_color << endl;
    if (!set) {
        cout << "set is nullptr!" << endl;
    }
    cout << "set size: " << set->theset.size() << endl;

    for (auto p : set->theset) {
        if (p->getInfo().alive && p->getInfo().pos == input.startPos && p->getInfo().colour == cur_color) {
            cout << "checking if valid" << endl;
            cout << "current type: " << p->getInfo().type << endl;
            cout << "current color: " << p->getInfo().colour << endl;
            cout << "validpos size: " << p->validpos().size() << endl;
            for (auto vp : p->validpos()) {
                cout << "vp position" << vp.row << ", " << vp.col << endl;
                if (vp == input.endPos) {
                    cout << "This is valid!" << endl;
                    return true;
                }
            }
        }
    }
    cout << "This is invalid!" << endl;
    return false;
}

void Game::update(Input input) {
    cout << "Updating" << endl;
    // including adding past moves, mutate pieces' states and notify board and mutate isWhite
    string input_type;
    string input_color;
    string captype = "NC";
    int spmv = 0;
//    int input_sm;
    Piece *cur_p; // moved piece
    Piece *cap_p = nullptr; // possible captured piece
    if (isValid(input)) {
        cout << "valid input" << endl;
        for (auto p : set->theset) {
            if (p->getInfo().pos == input.startPos) {
                cur_p = p;
                input_type = p->getInfo().type;
                input_color = p->getInfo().colour;
                if (input_type == "King" && abs(input.startPos.col-input.endPos.col) == 2) {
                    spmv = 1;
                }
                if (input_type == "Pawn" && input_color == "w") {
                    for (auto p: set->theset) {
                        if (p->getInfo().pos == Position{input.endPos.row-1, input.endPos.col} && p->getInfo().type == "Pawn") {
                            if (dynamic_cast<Pawn *>(p)->isimme()) spmv = 2;
                        }
                    }
                }
                if (input_type == "Pawn" && input_color == "b") {
                    for (auto p: set->theset) {
                        if (p->getInfo().pos == Position{input.endPos.row+1, input.endPos.col} && p->getInfo().type == "Pawn") {
                            if (dynamic_cast<Pawn *>(p)->isimme()) spmv = 2;
                        }
                    }
                }
                // TODO: En passant
                // DONE
            }
            if (p->getInfo().pos == input.endPos) {
                cap_p = p;
                captype = p->getInfo().type;
            }
        }
        if (input.promotion != "NP" && input_type == "Pawn" && 
                ( (isWhite && input.endPos.row == 8) || (!isWhite && input.endPos.row == 1) )){
            spmv = 3;
        }
        Move move = {input.startPos, input.endPos, input_color, input_type, captype, spmv};
        pastMoves.emplace_back(move);
        cur_p->setPos(input.endPos);
        cur_p->setMove(true);
        if (cap_p) cap_p->setAlive(false);
        if (spmv == 1) {
            if (input.startPos.col-input.endPos.col == 2 && isWhite) {
                // White castling short
                for (auto p : set->theset) {
                    if (p->getInfo().pos == Position{1, 8} 
                            && p->getInfo().type == "Rook" && p->getInfo().colour == "w"&& !p->getInfo().moved
                            /*not necessary, only for testing*/) {//corresponding Rook
                        p->setPos(Position{1, 6});
                        p->setMove(true);
                        break;
                    }
                }
            }
            else if (input.startPos.col-input.endPos.col == 2 && !isWhite) {
                // Black castling short
                for (auto p : set->theset) {
                    if (p->getInfo().pos == Position{8, 8}
                            && p->getInfo().type == "Rook" && p->getInfo().colour == "b" && !p->getInfo().moved
                            /*not necessary, only for testing*/) {
                        p->setPos(Position{8, 6});
                        p->setMove(true);
                        break;
                    }
                }
            }
            else if (input.startPos.col-input.endPos.col == -2 && isWhite) {
                // White castling long
                for (auto p : set->theset) {
                    if (p->getInfo().pos == Position{1, 1}
                            && p->getInfo().type == "Rook" && p->getInfo().colour == "w" && !p->getInfo().moved
                            /*not necessary, only for testing*/) {
                        p->setPos(Position{1, 4});
                        p->setMove(true);
                        break;
                    }
                }
            }
            else if (input.startPos.col-input.endPos.col == -2 && !isWhite) {
                // Black castling long
                for (auto p : set->theset) {
                    if (p->getInfo().pos == Position{8, 1}
                            && p->getInfo().type == "Rook" && p->getInfo().colour == "b" && !p->getInfo().moved 
                            /*not necessary, only for testing*/) {
                        p->setPos(Position{8, 4});
                        p->setMove(true);
                        break;
                    }
                }
            }
            else {// should not happen
                throw "Incorrect castling!";
            }
        }
        else if (spmv == 2) { //TODO: actually implement en passant determination
            if (isWhite) { // Black pawn get captured
                for (auto p : set->theset) {
                    if (p->getInfo().pos == Position{input.endPos.row-1, input.endPos.col}) {
                        p->setAlive(false);
                        break;
                    }
                }
            }
            else { // White pawn get capturd
                for (auto p : set->theset) {
                    if (p->getInfo().pos == Position{input.endPos.row+1, input.endPos.col}) {
                        p->setAlive(false);
                        break;
                    }
                }
            }
        }
        else if (spmv == 3) {
//            Piece* np = new Piece;
            string cmd;
            cin >> cmd;
            if (cmd == "Q") input.promotion = "Queen";
            if (cmd == "N") input.promotion = "Knight";
            if (cmd == "R") input.promotion = "Rook";
            if (cmd == "B") input.promotion = "Bishop";
            if (input.promotion == "Queen") {
//                Piece* np = new Queen;
                Queen* np = new Queen{input_color, input.promotion, true, true, cur_p->getInfo().pos, set};
                dynamic_cast<Pawn *>(cur_p)->promote(np);

            }
            else if (input.promotion == "Rook") {
//                Piece* np = new Rook;
                Rook* np = new Rook{input_color, input.promotion, true, true, cur_p->getInfo().pos, set};
                dynamic_cast<Pawn *>(cur_p)->promote(np);

            }
            else if (input.promotion == "Knight") {
//                Piece* np = new Knight;
                Knight* np = new Knight{input_color, input.promotion, true, true, cur_p->getInfo().pos, set};
                dynamic_cast<Pawn *>(cur_p)->promote(np);

            }
            else if (input.promotion == "Bishop") {
//                Piece* np = new Bishop;
                Bishop* np = new Bishop{input_color, input.promotion, true, true, cur_p->getInfo().pos, set};
                dynamic_cast<Pawn *>(cur_p)->promote(np);

            }
            else {//should not happen
                throw "no promotion!";
            }
//            dynamic_cast<Pawn *>(cur_p)->promote(np);
//            set->theset.emplace_back(np);
        }
        if (!set) cout << "2. set is nullptr" << endl;
        cout << "2. set size is " << set->theset.size() << endl;
        theBoard->tDisplay(set);
        theBoard->gDisplay(set);
        isWhite = !isWhite; // switch to the other player
    }
}

bool Game::isChecked() { // Check whether after move, the OPPONENT IS IN CHECK
    // e.g., after white player moved validly, now the current 
    // color is black and this checks if the black player is in check
    string cur_color;
    string op_color;
    if (isWhite) {cur_color = "w"; op_color = "b";}
    else {cur_color = "b"; op_color = "w";}
    for (auto k : set->theset) {
        if (k->getInfo().type == "King" && k->getInfo().colour == cur_color) {
            for (auto p : set->theset) {
                if (p->getInfo().colour == op_color) {
                    for (auto cappos : p->cappos()) {
                        if (k->getInfo().pos == cappos) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Game::isCheckmated() { 
    // Check whether after move, the OPPONENT is checkmated
    // e.g., white player moved validly, now the current 
    // color is black and this checks if the black player is in check
    if (isChecked()) {
        string cur_color;
        if (isWhite) cur_color = "w";
        else cur_color = "b";
        for (auto k : set->theset) {
            if (k->getInfo().type == "King" && k->getInfo().colour == cur_color) {
                return (k->validpos().size() == 0);
            }
        }
    }
    return false;
}

bool Game::isStatemate() {
    // Check whether after move, the OPPONENT is in stalemate
    // e.g., white player moved validly, now the current 
    // color is black and this checks if the black player is in stalemate
    if (!isChecked()) {
        string cur_color;
        if (isWhite) cur_color = "w";
        else cur_color = "b";
        for (auto k : set->theset) {
            if (k->getInfo().type == "King" && k->getInfo().colour == cur_color) {
                return (k->validpos().size() == 0);
            }
        }
    }
    return false;
}


