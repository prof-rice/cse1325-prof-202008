#include <iostream>
using namespace std;

int main() {
  string s1 = "Thing 1\n";  // Assignment operator
  string s2("Thing 2\n");   // Direct
  string s3{"Thing 3\n"};   // Uniform (Brace)

  cout << s1 << s2 << s3 << endl;
}
