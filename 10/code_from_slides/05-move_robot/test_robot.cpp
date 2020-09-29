#include "robot.h"
#include "coordinate.h"
#include <iostream>
#include <sstream>

/*
 Test Robot class

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
 
 int main() {
  int result = 0;      // Set to non-zero code if failed
  int test_vector = 1; // Bitmask for calculating codes

  {
  ///////////////////////////////////
  // Robot static initialization
  std::string expected = "Robot00 (0,0)  Robot02 (0,2)  Robot20 (2,0)  Robot22 (2,2)  ";
  std::ostringstream actual;
  for(int x = 0; x < 3; x += 2) {
    for(int y = 0; y < 3; y += 2) {
      Robot r("Robot" + std::to_string(x) + std::to_string(y), Coordinate(x, y));
      actual << r << "  ";
    }
  }

  if (expected != actual.str()) {
    std::cerr << "FAIL: Robot static initialization" << std::endl;
    std::cerr << "  Expected: \"" << expected << "\"" << std::endl;
    std::cerr << "  Actual:   \"" << actual.str() << "\"" << std::endl << std::endl;
    result |= test_vector;  // Fail this test vector
  }
  test_vector <<= 1;
  }{
  ///////////////////////////////////
  // Robot random initialization
  std::string expected = "Robot1 (13,16)  Robot2 (27,25)  Robot3 (23,25)  Robot4 (16,12)  Robot5 (9,1)  ";
  std::ostringstream actual;
  for(int i = 0; i < 5; ++i) {
    Robot r;
    actual << r << "  ";
  }

  if (expected != actual.str()) {
    std::cerr << "FAIL: robot.h: random initialization" << std::endl;
    std::cerr << "  Expected: \"" << expected << '"' << std::endl;
    std::cerr << "  Actual:   \"" << actual.str() << '"' << std::endl << std::endl;
    result |= test_vector;  // Fail this test vector
  }
  test_vector <<= 1;
  }{
  /////////////////
  // Robot movement
  std::string expected = "Marvin (5,5)  Marvin (2,5)  Marvin (2,3)  Marvin (22,3)  Marvin (25,8)  ";
  std::ostringstream actual;

  Robot r{"Marvin", Coordinate{5, 5}};
  actual << r << "  ";

  // Define our directions (we’ll need these for the game, too!)
  Coordinate left{-1,0,true};
  Coordinate up_left{-1,-1,true};
  Coordinate up{0,-1,true};
  Coordinate up_right{1,-1,true};
  Coordinate right{1,0,true};
  Coordinate down_right{1,1,true};
  Coordinate down{0,1,true};
  Coordinate down_left{-1,1,true};
  Coordinate stay{0,0,true};

  for(int i=0; i<3; ++i) r.move(left); // Move "Marvin" left 3 spaces, to (2, 5)
  actual << r << "  ";
  for(int i=0; i<2; ++i) r.move(up); // Move "Marvin" up 2 spaces, to (2, 3)
  actual << r << "  ";
  for(int i=0; i<20; ++i) r.move(right); // Move "Marvin" right 20 spaces, to (22, 3)
  actual << r << "  ";
  for(int i=0; i<3; ++i) r.move(down_right); // Move "Marvin" down and right, to (25, 8)
  for(int i=0; i<2; ++i) r.move(down);
  actual << r << "  ";

  if (expected != actual.str()) {
    std::cerr << "FAIL: Robot movement" << std::endl;
    std::cerr << "  Expected: \"" << expected << '"' << std::endl;
    std::cerr << "  Actual:   \"" << actual.str() << '"' << std::endl << std::endl;
    result |= test_vector;  // Fail this test vector
  }
  test_vector <<= 1;
  }

  if (result) std::cerr << "FAIL: Code " << result << std::endl;
  return result;
}

