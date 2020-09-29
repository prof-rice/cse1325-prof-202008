#include "coordinate.h"
#include <cstdlib>
#include <cassert>

/*
 Class Coordinate - Models a location on a 2D grid.

 @author      George F. Rice
 @copyright   Copyright 2017-2019
 @version     2.0

 This file is part of Roving Robots.

 Roving Robots is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Roving Robots is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
*/ 
 
Coordinate::Coordinate(int x, int y, bool direction) : _x{x}, _y{y} {
    validate(direction);
}
Coordinate::Coordinate() 
    : Coordinate{std::rand() % (MAX_X+1), std::rand() % (MAX_Y+1)} {}
void Coordinate::validate(bool direction) {
    if (direction) {
        assert(-1 <=_x && _x <= 1);
        assert(-1 <=_y && _y <= 1);
    } else {
        assert(0 <=_x && _x <= MAX_X);
        assert(0 <=_y && _y <= MAX_Y);
    }
}
int Coordinate::x( ) const {return _x;}
int Coordinate::y( ) const {return _y;}
std::ostream& operator<<(std::ostream& ost, const Coordinate& c) {
    ost << '(' << c.x() << ',' << c.y() << ')';
    return ost;
}
Coordinate Coordinate::operator+(const Coordinate& c) {
    return Coordinate{std::min(std::max(_x+c._x, 0), MAX_X),
                      std::min(std::max(_y+c._y, 0), MAX_Y)};
}
bool Coordinate::operator==(const Coordinate& c) {return (_x == c._x && _y == c._y);}
bool Coordinate::operator!=(const Coordinate& c) {return !(*this == c);}

