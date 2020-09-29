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
  }

  if (result) std::cerr << "FAIL: Code " << result << std::endl;
  return result;
}

