#include "grid.h"
#include <iostream>
#include <ctime>

int main() {
  srand (time(NULL));

  std::cout << "Grid at center location" << std::endl << std::endl;
  std::cout << Grid{} << std::endl;
}
