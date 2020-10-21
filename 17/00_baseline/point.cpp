#include "point.h"

namespace Graph_lib {   // our graphics interface is in Graph_lib
Point::Point(int x, int y) : _x(x), _y(y) { }

int Point::x() const {return _x;}
int Point::y() const {return _y;}

// Define stream out operator
std::ostream& operator<<(std::ostream& ost, const Point& p) {
    ost << "(" << p._x << "," << p._y << ")";
    return ost;
}

// Define equality of points
inline bool Point::operator==(Point rhs) {return _x==rhs._x && _y==rhs._y;} 
inline bool Point::operator!=(Point rhs) {return !(*this==rhs);}
}
