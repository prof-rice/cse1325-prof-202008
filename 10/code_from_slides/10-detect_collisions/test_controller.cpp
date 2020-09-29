#include "controller.h"
#include <vector>
#include <iostream>

/*
 Test Controller - Tests the Controller and View classes

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

class Test_vector {
  public:
    Test_vector(char cmd, Coordinate coordinate)
        : _cmd{cmd}, _coordinate{coordinate}, _vector{vectors++} { }
    char cmd() {return _cmd;}
    void verify(Coordinate coordinate) {
        if (coordinate != _coordinate) {
            std::cerr << "FAIL: Vector " << _vector << " cmd " << _cmd << std::endl;
            std::cerr << "  Expected: " << _coordinate << std::endl;
            std::cerr << "  Actual:   " <<  coordinate << std::endl;
        }
    }
  private:
    char _cmd;
    Coordinate _coordinate;
    int _vector;
    static int vectors;   // Automatically number the test vectors as constructed
};
int Test_vector::vectors = 0;

int main() {
    // These are called "test vectors"
    std::vector<Test_vector> tests;
    tests.push_back(Test_vector{'4', Coordinate{13,14}});
    tests.push_back(Test_vector{'9', Coordinate{14,13}});
    tests.push_back(Test_vector{'3', Coordinate{15,14}});
    tests.push_back(Test_vector{'5', Coordinate{15,14}});
    tests.push_back(Test_vector{'2', Coordinate{15,15}});
    tests.push_back(Test_vector{'6', Coordinate{16,15}});
    tests.push_back(Test_vector{'1', Coordinate{15,16}});
    tests.push_back(Test_vector{'8', Coordinate{15,15}});
    tests.push_back(Test_vector{'7', Coordinate{14,14}});

    // Throw the test vectors at Controller
    Controller c;
    for(auto tv : tests) {
        c.execute_cmd(tv.cmd());
        tv.verify(c._player.coordinate());
    }
}
      
  
