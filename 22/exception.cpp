#include <iostream>

class Ie : public std::exception { };

int main() {
  try {
    throw Ie{"Hello, world"};
  } catch(std::exception& e) {
    std::cerr << "Caught an exception\n";
  } catch(std::exception* e) {
    std::cerr << "Caught an exception pointer\n";
  }
}
