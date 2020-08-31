#include <iostream>
using namespace std;

int main() {
  for(int i=10; i>0; --i) cout << i << endl;
  cerr << "ERROR: System timed out" << endl;
  return -1;
  // In bash after running this, try:
  //     if [ $? = 0 ] ; then echo true; fi

  // ALWAYS return non-zero if on program failure to the OS can react
  // GOOD IDEA to return zero on success (but that's the default)
}
