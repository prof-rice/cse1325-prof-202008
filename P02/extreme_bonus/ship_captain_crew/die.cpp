#include "die.h"
#include <cstdlib>

Die::Die(int faces) : _faces{faces}, _keep{false}, _value{1} { }
const int Die::faces() {return _faces;}
void Die::roll() {
    if(!_keep) _value = 1+std::rand()%_faces;
}
int Die::value() {return _value;}
void Die::keep(bool k) {_keep = k;}
bool Die::keep() {return _keep;}
