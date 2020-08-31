#include <iostream>
#include <iomanip>
#include <bitset>

int main() {
  std::string s = "The answer is ";
  std::cout << std::showbase << s << 32'768 << std::endl;
}
