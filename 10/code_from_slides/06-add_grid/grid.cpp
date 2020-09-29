 #include "grid.h"
 
/*
 Class Grid - Models a 2D grid.

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

Grid::Grid(int num_robots) : _player{Robot{"Ralph", Coordinate{MAX_X/2, MAX_Y/2}}} {}

Robot Grid::player( ) const {return _player;}
void Grid::move_player(Coordinate direction) {
    _player.move(direction);
}
std::ostream& operator<<(std::ostream& ost, const Grid& grid) {
    Coordinate c = grid.player().coordinate();
    for (int x = 0; x <= MAX_X; ++x) {
      for (int y = 0; y <= MAX_Y; ++y) {
        ost << ((x == c.x() && y == c.y()) ? 'R' : '.');
      }
      ost << std::endl;
    }
    return ost;
}
