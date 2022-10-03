#ifndef _BOARD_H_
#define _BOARD_H_

#include "textdisplay.h"
#include "graphicsdisplay.h"


class Board{
    TextDisplay * td;
    GraphicsDisplay * gd;
    public:
	void create();
    void tDisplay(Pieceset *p);
    void gDisplay(Pieceset *p);
	~Board();
};




#endif 
