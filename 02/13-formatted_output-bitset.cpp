#include <iostream>
#include <iomanip>
#include <bitset>

int main() {
  std::string s = "The answer is ";
  std::cout << std::showbase << s << std::bitset<8>{42} << std::endl;
}
