#include "controller.h"
#include <iostream>

/*
 Class Controller - Controls the Roving Robots game (CLI).

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

/* ***********************************************************
 Lots of C tap dancing to get single characters from the Linux
 console without requiring a following Enter. Don't try this
 at home. If you want to do much of this, learn ncurses instead!

 WARNING: Esc must be pressed TWICE to register as a single press.

 WARNING: Only handles single-char and selected keypad keys.
          Does NOT handle function keys and other multi-char keys.

 WARNING: Does NOT work with Windows! Untested on OS X! 

 Adapted from 
 https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html

*/
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
struct termios orig_termios;
void disable_raw_mode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}
void enable_raw_mode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disable_raw_mode);
  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
char instachar() {
  char cmd = ' ';
  int state = 0; // keypad / Fn is Esc [ code
  enable_raw_mode();
  while(true) {
      read(STDIN_FILENO, &cmd, 1);
      if (cmd == 27 && state == 0) state = 1;
      else if (cmd == 91 && state == 1) state = 2;
      else break;
  }
  if (state == 2) {
      switch (cmd) { // translate code to char
          case 'F': cmd = '1'; break;
          case 'B': cmd = '2'; break;
          case '6': cmd = '3'; break;
          case 'D': cmd = '4'; break;
          case 'E': cmd = '5'; break;
          case 'C': cmd = '6'; break;
          case 'H': cmd = '7'; break;
          case 'A': cmd = '8'; break;
          case '5': cmd = '9'; break;
          case '2': cmd = '0'; break;
          case '3': cmd = '.'; break;
      }
  }
  disable_raw_mode();
  return cmd;
}
/* ***********************************************************
*/

Controller::Controller() : _grid{rand()%40+10}, _view{_grid} {}

void Controller::cli() {
    _grid.detect_collisions(); // Destroy any robots trying to share a space

    char cmd = 'x';
    while (cmd != '0' && _grid.player_is_alive() && _grid.any_robots_alive()) {
        _view.print_banner();
        _view.print_grid();
        std::cout << _grid.player() << " Command? "; std::cout.flush();

        // std::cin >> cmd;  // The C++ way
        cmd = instachar();   // The no Enter key way

        std::cout << cmd << " (" << int(cmd) << ')' << std::endl;
        execute_cmd(cmd);
        _grid.animate_robots();
        _grid.detect_collisions();
    }
    if (_grid.player_is_alive()) _view.trophy(); else _view.explosion();
    _view.print_grid();
};

void Controller::execute_cmd(char cmd) {
    // Define our directions
    const static Coordinate left      {-1, 0, true};
    const static Coordinate up_left   {-1,-1, true};
    const static Coordinate up        { 0,-1, true};
    const static Coordinate up_right  { 1,-1, true};
    const static Coordinate right     { 1, 0, true};
    const static Coordinate down_right{ 1, 1, true};
    const static Coordinate down      { 0, 1, true};
    const static Coordinate down_left {-1, 1, true};
    const static Coordinate stay      { 0, 0, true};

    // Map keyboard commands to directions
    if (cmd == '1') {_grid.move_player(down_left ); }
    if (cmd == '2') {_grid.move_player(down      ); }
    if (cmd == '3') {_grid.move_player(down_right); }
    if (cmd == '4') {_grid.move_player(left      ); }
    if (cmd == '5') {_grid.move_player(stay      ); }
    if (cmd == '6') {_grid.move_player(right     ); }
    if (cmd == '7') {_grid.move_player(up_left   ); }
    if (cmd == '8') {_grid.move_player(up        ); }
    if (cmd == '9') {_grid.move_player(up_right  ); }
    if (cmd == '.') {_grid.teleport(); }
};
