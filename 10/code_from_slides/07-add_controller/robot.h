#ifndef __ROBOT_H
#define __ROBOT_H

#include "coordinate.h"
#include <string>

/*
 Class Robot - Models an avatar on the grid

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

class Robot {
  public:
    Robot(std::string id, Coordinate coordinate);
    Robot();

    std::string id() const;
    Coordinate coordinate() const;
    void move(Coordinate direction);
  private:
    std::string _id;            // "Name" of the robot to display on-screen
    Coordinate _coordinate;     // location of robot on an X-Y grid
    static int _next_id;        // Used to generate unique robot ids

    std::string generate_id();  // generate unique ID for each robot
};
std::ostream& operator<<(std::ostream& ost, const Robot& robot);
#endif
