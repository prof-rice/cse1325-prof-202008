#include "point_oo_method.h"

namespace Graph_lib {   // our graphics interface is in Graph_lib
Point::Point(int x, int y) : _x(x), _y(y) { }

// Define equality of points
inline bool Point::operator==(Point rhs) { return _x==rhs._x && _y==rhs._y; } 
inline bool Point::operator!=(Point rhs) { return !(*this==rhs); }
}
