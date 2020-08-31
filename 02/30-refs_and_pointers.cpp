#include <iostream>
using namespace std;

int main() {
  int i = 42;

  // A "reference" is an alias for another variable
  // It's like a pointer, but it MUST reference a valid variable
  //   AND it can never change to reference a different variable
  int& ir = i;  // ir is now an "alias of" i
  cout << "i = " << i << " and ir references " << ir << endl;

  // If we change the reference, we change the variable it references
  ir = 7;
  cout << "i = " << i << " and ir references " << ir << endl;

  // As you know, a pointer contains the address that may be of a variable
  int* ip = &i; // ip now "points to" i

  // *ip "dereferences" ip, that is, returns what ip points to
  cout << "ip = " << ip << " which points to " << *ip << endl;

  // We can modify by "dereferencing" the pointer as well
  *ip = 256;
  cout << "i = " << i << ", ir references " << ir
       << " and ip = " << ip << " which points to " << *ip << endl;
}
