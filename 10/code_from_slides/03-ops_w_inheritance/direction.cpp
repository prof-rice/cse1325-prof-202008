#include "direction.h"
#include <cstdlib>
#include <cassert>

/*
 Class Direction - Models a direction on a 2D grid.

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
 
Direction::Direction(int x, int y) : Coordinate(x,y,true) {
    validate();
}
void Direction::validate() {
    assert(-1 <=_x && _x <= 1);
    assert(-1 <=_y && _y <= 1);
}

