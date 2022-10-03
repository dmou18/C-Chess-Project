#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include <string>
#include "Pieceset.h"
#include "Info.h"
#include "piece.h"


class TextDisplay {
    std::vector<std::vector<char>> theDisplay;
    public:
	TextDisplay();
    void tDisplay(Pieceset *p);
	friend std::ostream &operator<<(std::ostream &out,const TextDisplay &td);
};

#endif


