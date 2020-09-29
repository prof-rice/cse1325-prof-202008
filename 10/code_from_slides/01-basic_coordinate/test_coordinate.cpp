#include "coordinate.h"
#include <iostream>

/*
 Test Coordinate class

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
  int result = 0;       // Set to non-zero code if failed
  int test_vector = 1;  // First error code

  std::string expected = "(0,0)  (0,3)  (0,7)  (2,0)  (2,3)  (2,6)  (4,0)  (4,3)  (4,6)  ";
  std::string actual = "";

  for(int x = 0; x < 3; ++x) {
    for(int y = 0; y < 3; ++y) {
      Coordinate c(x*2, y*3);
      actual += '(' + std::to_string(c.x()) + ',' + std::to_string(c.y()) + ")  ";
    }
  }

  if (expected != actual) {
    std::cerr << "FAIL: Coordinate static initialization" << std::endl;
    std::cerr << "  Expected: \"" << expected << '"' << std::endl;
    std::cerr << "  Actual:   \"" << actual << '"' << std::endl << std::endl;
    result |= test_vector;  // Set a bit for this failure
  }
  test_vector <<= 1;  // Shift left 1 bit, equivalent to *= 2, after each test

  return result;
}
