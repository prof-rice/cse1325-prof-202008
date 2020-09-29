#include "robot.h"

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

Robot::Robot(std::string robot_id, Coordinate coordinate) 
    : _id{robot_id}, _coordinate{coordinate} { }
Robot::Robot() : Robot(generate_id(), Coordinate()) { }
std::string Robot::id( ) const {return _id;}
Coordinate Robot::coordinate( ) const {return _coordinate;}
void Robot::move(Coordinate direction) {_coordinate = _coordinate + direction;}
std::ostream& operator<<(std::ostream& ost, const Robot& robot) {
    ost << robot.id() << ' ' << robot.coordinate();
    return ost;
}
int Robot::_next_id = 0;
std::string Robot::generate_id() {      // generate unique ID for each robot
  return "Robot" + std::to_string(++_next_id);
}
