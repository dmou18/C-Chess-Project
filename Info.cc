#include "Info.h"
using namespace std;

Info::Info(string colour, string type, bool moved, bool alive, Position pos) :\
        colour{colour}, type{type}, moved{moved}, alive{alive}, pos{pos} {}


