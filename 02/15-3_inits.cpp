#include <iostream>

int main() {
  std::string s1 = "Thing 1\n";  // Assignment operator
  std::string s2("Thing 2\n");   // Direct
  std::string s3{"Thing 3\n"};   // Uniform (Brace)

  std::cout << s1 << s2 << s3 << std::endl;
}
