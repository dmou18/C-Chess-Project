#include "graphicsdisplay.h"

using namespace std;


GraphicsDisplay::GraphicsDisplay(){
    x.fillRectangle(0,0,500,500,0);
    const int size = 40;
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            int y =i*size+50;
            int z =j*size+50;
                 if((i+j)%2 == 0){
                    x.fillRectangle(z-10,y-30,40,40,4);
                   // x.drawString(z,y," ");
                }else{
                    x.fillRectangle(z-10,y-30,40,40,3);
                   // x.drawString(z,y,"-");
                }
           if(i ==0 && j==0) x.drawBigString(z,y,"r");
            if(i ==0 && j==1) x.drawBigString(z,y,"n");
            if(i ==0 && j==2) x.drawBigString(z,y,"b");
            if(i ==0 && j==3) x.drawBigString(z,y,"q");
            if(i ==0 && j==4) x.drawBigString(z,y,"k");
            if(i ==0 && j==5) x.drawBigString(z,y,"b");
            if(i ==0 && j==6) x.drawBigString(z,y,"n");
            if(i ==0 && j==7) x.drawBigString(z,y,"r");

            if(i==1) x.drawBigString(z,y,"p");
            
      /*    if(i>1 && i< 6){
                if((i+j)%2 == 0){
                    x.fillRectangle(z-10,y-10,20,20,0);
                   // x.drawString(z,y," ");
                }else{
                    x.fillRectangle(z-10,y-10,20,20,3);
                   // x.drawString(z,y,"-");
                }
          }*/
            if(i==6) x.drawBigString(z,y,"P");
            if(i ==7 && j==0) x.drawBigString(z,y,"R");
            if(i ==7 && j==1) x.drawBigString(z,y,"N");
            if(i ==7 && j==2) x.drawBigString(z,y,"B");
            if(i ==7 && j==3) x.drawBigString(z,y,"Q");
            if(i ==7 && j==4) x.drawBigString(z,y,"K");
            if(i ==7 && j==5) x.drawBigString(z,y,"B");
            if(i ==7 && j==6) x.drawBigString(z,y,"N");
            if(i ==7 && j==7) x.drawBigString(z,y,"R");
        }
    }

}


void GraphicsDisplay::gDisplay(Pieceset *p){
    x.fillRectangle(0,0,500,500,0);
    vector<vector<string>> v;
    v.resize(8);
    vector<Piece*> ps = p->theset;
    int n = ps.size();
    for(int i=0;i<8;++i){
        v[i].resize(8);
        for(int j=0;j<8;++j){
                v[i][j] = " ";
        }
    }
    for(int i=0;i<n;++i){
        string col = ps[i]->getInfo().colour;
        int row_num = 8 - ps[i]->getInfo().pos.row;
        int col_num = ps[i]->getInfo().pos.col - 1;
        string type = ps[i]->getInfo().type;
        bool alive = ps[i]->getInfo().alive;
        if(alive){
            if(col == "w"){
                if(type == "King")   v[row_num][col_num]="K";
                if(type == "Queen")  v[row_num][col_num]="Q";
                if(type == "Bishop") v[row_num][col_num]="B";
                if(type == "Rook")   v[row_num][col_num]="R";
                if(type == "Knight") v[row_num][col_num]="N";
                if(type == "Pawn")   v[row_num][col_num]="P";
            }else{
                if(type == "King")   v[row_num][col_num]="k";
                if(type == "Queen")  v[row_num][col_num]="q";
                if(type == "Bishop") v[row_num][col_num]="b";
                if(type == "Rook")   v[row_num][col_num]="r";
                if(type == "Knight") v[row_num][col_num]="n";
                if(type == "Pawn")   v[row_num][col_num]="p";   
            } 
        }
    }
    int size =40;
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            if((i+j)%2 == 0){
                 x.fillRectangle(j*size+40,i*size+20,40,40,4);
            }else{
                 x.fillRectangle(j*size+40,i*size+20,40,40,3);   
            }
            x.drawBigString(j*size+50,i*size+50,v[i][j]);
        }
    }
}
