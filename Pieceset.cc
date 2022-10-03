#include "Pieceset.h"

Pieceset::~Pieceset() {
    int len = theset.size();
    for (int i = len - 1; i >= 0; --i) {
        delete theset[i];
        theset.pop_back();
    }
}
