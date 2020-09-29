#ifndef __COORDINATE_H
#define __COORDINATE_H

#include <ostream>

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

const int MAX_X = 29; // x is in range [0,MAX_X]
const int MAX_Y = 29; // y is in range [0,MAX_Y]
 
class Coordinate {
  public:
    Coordinate(int x, int y, bool direction = false);
    Coordinate();
    int x() const;
    int y() const;
    Coordinate operator+(const Coordinate& c);
    bool operator==(const Coordinate& c);
    bool operator!=(const Coordinate& c);
  private:
    int _x;
    int _y;
    void validate(bool direction);
};
std::ostream& operator<<(std::ostream& ost, const Coordinate& c);
#endif
