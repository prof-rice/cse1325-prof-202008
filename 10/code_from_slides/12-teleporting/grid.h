#ifndef __GRID_H
#define __GRID_H

#include "robot.h"
#include <ostream>
#include <vector>

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
 
class Grid {
  public:
    Grid(int num_robots = 30);
    Robot player() const;
    void move_player(Coordinate direction);
    void teleport();
    void animate_robots();
    void detect_collisions();
    bool player_is_alive() const;
    friend std::ostream& operator<<(std::ostream& ost, const Grid& grid);
  private:
    Robot _player; // The player wandering the grid
    std::vector<Robot> _robots;  // The enemy robots
};
#endif 
