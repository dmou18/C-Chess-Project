#include "textdisplay.h"

using namespace std;




TextDisplay::TextDisplay(){
  theDisplay.resize(8);
  for(int i=0;i<8;++i){
    theDisplay[i].resize(8);
    for(int j=0;j<8;++j){
        if(i == 0 && j == 0)  theDisplay[i][j]='r';
        if(i == 0 && j == 1)  theDisplay[i][j]='n';
        if(i == 0 && j == 2)  theDisplay[i][j]='b';
        if(i == 0 && j == 3)  theDisplay[i][j]='q';
        if(i == 0 && j == 4)  theDisplay[i][j]='k';
        if(i == 0 && j == 5)  theDisplay[i][j]='b';
        if(i == 0 && j == 6)  theDisplay[i][j]='n';
        if(i == 0 && j == 7)  theDisplay[i][j]='r'; //the display of white 

        if(i == 1)  theDisplay[i][j]='p'; // white pawn

        if(i > 1 && i < 6)  {
            if((i+j) % 2 == 0){
                theDisplay[i][j]=' ';
            }else{
                theDisplay[i][j]='-';
            }
        }   // the white squares and dark squares

        if(i == 6)  theDisplay[i][j]='P'; // black pawn
       
        if(i == 7 && j == 0)  theDisplay[i][j]='R';
        if(i == 7 && j == 1)  theDisplay[i][j]='N';
        if(i == 7 && j == 2)  theDisplay[i][j]='B';
        if(i == 7 && j == 3)  theDisplay[i][j]='Q';
        if(i == 7 && j == 4)  theDisplay[i][j]='K';
        if(i == 7 && j == 5)  theDisplay[i][j]='B';
        if(i == 7 && j == 6)  theDisplay[i][j]='N';
        if(i == 7 && j == 7)  theDisplay[i][j]='R'; //the display of black
    }
  }
}


void TextDisplay::tDisplay(Pieceset *p){
    vector<Piece*> ps = p->theset;
    int n = ps.size();
    cout << "In textdisplay, set size is " << n << endl;
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            if((i+j)%2 == 0){
                theDisplay[i][j]=' ';
            }else{
                theDisplay[i][j]='-';
            }
        }
    }

    for(int i = 0;i<n;++i){
        string col = ps[i]->getInfo().colour;
        int row_num = 8-ps[i]->getInfo().pos.row;
        int col_num = ps[i]->getInfo().pos.col - 1;
        string type = ps[i]->getInfo().type;
        bool alive = ps[i]->getInfo().alive;
        if(alive){
        if(col == "w"){
            if(type == "King") theDisplay[row_num][col_num]='K';
            if(type == "Queen") theDisplay[row_num][col_num]='Q';
            if(type == "Bishop") theDisplay[row_num][col_num]='B';
            if(type == "Rook") theDisplay[row_num][col_num]='R';
            if(type == "Knight") theDisplay[row_num][col_num]='N';
            if(type == "Pawn") theDisplay[row_num][col_num]='P';
        }else{
            if(type == "King") theDisplay[row_num][col_num]='k';
            if(type == "Queen") theDisplay[row_num][col_num]='q';
            if(type == "Bishop") theDisplay[row_num][col_num]='b';
            if(type == "Rook") theDisplay[row_num][col_num]='r';
            if(type == "Knight") theDisplay[row_num][col_num]='n';
            if(type == "Pawn") theDisplay[row_num][col_num]='p';   
        }
     }
    }
}


ostream &operator<<(ostream &out,const TextDisplay &td){
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            out<<td.theDisplay[i][j];
        }
        out<<endl;
    }
    return out;
}
