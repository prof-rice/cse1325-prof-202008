#include "die.h"
#include <cstdlib>

Die::Die(int faces) : _faces{faces} { }
int Die::faces() {return _faces;}
int Die::roll() {return 1+std::rand()%_faces;}

