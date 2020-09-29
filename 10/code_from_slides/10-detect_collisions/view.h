#ifndef __VIEW_H
#define __VIEW_H

#include "grid.h"

/*
 Class View - Displays Roving Robots game (CLI) screen elements.

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

class View {
  public:
    View(Grid& grid);
    void print_banner();
    void print_grid();
    void trophy();
    void explosion();
  private:
    Grid& _grid; // The grid containing the roaming robots
};
#endif
