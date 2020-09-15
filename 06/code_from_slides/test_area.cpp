 #include <iostream>
 //#include <stdexcept>

 int area(int length, int width) {
   if (length<=0 || width<=0) throw std::runtime_error{"Bad area"};
   return length*width;
 }


 int main() {
    // TEST #1: Normal Sides
    if (area(14, 10) != 140) std::cerr << "FAIL: 10x14 not 140 but " << area(14,10) << std::endl;

    // TEST #2: Identical Length Sides
    if (area(10, 10) != 100) std::cerr << "FAIL: 10x10 not 100 but " << area(10,10) << std::endl;

    // TEST #3: Zero Length Side 
    if (area(0, 10) != 0) std::cerr << "FAIL: 0x10 not 0 but " << area(0,10) << std::endl;

    // TEST #4: Negative Length Side 
    try {
      int i = area(-1, -2);
      std::cerr << "FAIL: Negative side not exception but " << area(-1, -2) << std::endl;
    } catch (std::runtime_error e) {
    }
 }
