#include "die.h"
#include <cstdlib>

Die::Die(int faces) : _faces{faces}, _value{1} { }
const int Die::faces() {return _faces;}
void Die::roll() {_value = 1+std::rand()%_faces;}
int Die::value() {return _value;}

