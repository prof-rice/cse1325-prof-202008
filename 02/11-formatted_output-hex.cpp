#include <iostream>
#include <iomanip>

int main() {
  std::string s = "The answer is ";
  std::cout << std::hex << s << 42 << std::endl;
}
