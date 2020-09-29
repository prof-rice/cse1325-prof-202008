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

Grid::Grid(int num_robots) : _player{Robot{"Ralph", Coordinate{MAX_X/2, MAX_Y/2}}} {
    for (int i=0; i < num_robots; ++i) _robots.push_back(Robot{});
}
//Grid::Grid() : Grid(Robot{}) { }

Robot Grid::player( ) const {return _player;}
void Grid::move_player(Coordinate direction) {
    _player.move(direction);
}
void Grid::animate_robots( ) {
  for (Robot& robot : _robots) {
    if (robot.is_alive()) {
      int delta_x = robot.coordinate().x() -
                    _player.coordinate().x();
      int delta_y = robot.coordinate().y() -
                    _player.coordinate().y();
      robot.move(Coordinate{(delta_x < 0) - (delta_x > 0),        // Returns 1, 0, or -1
                            (delta_y < 0) - (delta_y > 0),true}); // based on sign
  //  robot.move(Coordinate(delta_x < 0 ? 1 : (delta_x > 0 ? -1 : 0), // Alt approach
  //                        delta_y < 0 ? 1 : (delta_y > 0 ? -1 : 0)));
    }
  }
}
void Grid::detect_collisions() {
    for (auto& r : _robots) {
        if (r.coordinate() == _player.coordinate()) {
            r.kill();
            _player.kill();
        }
        for (auto& r2 : _robots) {
            if (&r == &r2) break;
            if (r.coordinate() == r2.coordinate()) {
                r.kill();
                r2.kill();
            }
        }
    }
}
bool Grid::player_is_alive() const {return _player.is_alive();}
std::ostream& operator<<(std::ostream& ost, const Grid& grid) {
    Coordinate c = grid.player().coordinate();
    for (int y = 0; y <= MAX_Y; ++y) {
      for (int x = 0; x <= MAX_X; ++x) {
        Coordinate here{x,y};
        char icon = '.';
        for(auto r : grid._robots) 
            if (r.coordinate() == here) icon = (r.is_alive() ? 'X' : '*');
        if(grid._player.coordinate() == here) icon = (grid.player_is_alive() ? 'R' : '#');
        ost << icon;
      }
      ost << std::endl;
    }
    return ost;
}
