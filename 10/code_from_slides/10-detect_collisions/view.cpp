#include "view.h"
#include <iostream>

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

View::View(Grid& grid) : _grid{grid} {}
void View::print_banner(){
    for(int i=0; i<60; ++i) std::cout << '\n';
    std::cout << "============" << std::endl
              << "ROVING ROBOT" << std::endl
              << "============" << std::endl << std::endl;
}
void View::explosion() {
    for(int i=0; i<60; ++i) std::cout << '\n';
    std::cout << R"(
     _.-^^---....,,--
 _--                  --_
<                        >)
|                         |
 \._                   _./
    ```--. . , ; .--'''
          | |   |
       .-=||  | |=-.
       `-=#$%&%$#=-'
          | ;  :|
 _____.,-#%&$@%#&#~,._____  unknown
)" << std::endl;
}
void View::trophy() {
    for(int i=0; i<60; ++i) std::cout << '\n';
    std::cout << R"(

      (_v_)
       _|_
       | |
  |-----+-----|
  |   LONE    |
  | SURVIVOR  |
   '---------'
    \       /
     '.   .'
       | |
      .' '.
     _|___|
    [#######] apc 
)" << std::endl;
}
void View::print_grid() {std::cout << _grid << std::endl;}
