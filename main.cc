#include <iostream>
#include "game.h"
#include "move.h"
#include "position.h"

using namespace std;
<<<<<<< HEAD

int main() {
    Game g;
    
    string cmd;

    string s, s2;
    bool in_game = false;
=======

Position pos_convert(string s) {
    int col = s.at(0)-'a'+1;
    int row = s.at(1)-'1'+1;
    return Position {row, col};
}

int main() {
    Game g;
    float w_pt = 0;
    float b_pt = 0;
    string cmd;
    string s, s2;
    bool in_game = false;
    bool in_setup = false;
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
    while(cin >> cmd) {
        if (cmd == "game") {
            if (in_game) {
                cout << "already in game " << endl;
                continue;
            }
            cin >> s >> s2;
            if ( s == "computer") {}
            if ( s2 == "computer") {}
<<<<<<< HEAD
            g.newGmae();
            in_game = true;
        }
        else if (cmd == "resign"){

=======
            cout << "about to call g.newGame()" << endl;
            g.newGame();
            in_game = true;
        }
        else if (cmd == "resign"){
            if (g.whiteNow()) ++b_pt;
            else ++w_pt;
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
        }
        else if (cmd == "setup") {
            
        }
<<<<<<< HEAD
        else if (cmd == "move"){
            cin >> s >> s2;
            Position p1 = pos_convert(s);
            Position p2 = pos_convert(s2);
            Input i = {p1, p2, ""};
            g.update(i);
        } 
    }

=======
        else if (cmd == "move") {
            if (in_game) {
                cin >> s >> s2;
                Position p1 = pos_convert(s);
                Position p2 = pos_convert(s2);
                Input i = {p1, p2, ""};
                g.update(i);
            }
        }
    }
    cout << "Final Score:" << endl;
    cout << "White: " << w_pt << endl;
    cout << "Black: " << b_pt << endl;
>>>>>>> ae9365e8d51aa324f948772a048a2473ea55cd4e
    return 0;
}
