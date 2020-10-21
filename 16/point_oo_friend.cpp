#include "point_oo_friend.h"

namespace Graph_lib {   // our graphics interface is in Graph_lib
Point::Point(int x, int y) : _x(x), _y(y) { }

// Define equality of points
inline bool operator==(Point lhs, Point rhs) { return lhs._x==rhs._x && lhs._y==rhs._y; } 
inline bool operator!=(Point lhs, Point rhs) { return !(lhs==rhs); }
}
