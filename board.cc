#include <iostream>
#include "board.h"

using namespace std;


void Board::create(){
    this->td =  new TextDisplay{};
    cout<<*td;
    this->gd =  new GraphicsDisplay{};
}


Board::~Board(){
    delete td;
    delete gd;
}



void Board::tDisplay(Pieceset *p){
    td->tDisplay(p);
    cout<<(*td);
}

void Board::gDisplay(Pieceset *p){
    gd->gDisplay(p);
}
