#ifndef _GRAPHICSDISPLAY_H_
#define _GRAPHICSDISPLAY_H_

#include "window.h"
#include "textdisplay.h"


class GraphicsDisplay{
    const int n=8;
    Xwindow x;
    public:
	GraphicsDisplay();
    void gDisplay(Pieceset *p);
};

#endif
