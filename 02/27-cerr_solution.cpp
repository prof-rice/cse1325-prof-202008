#include <iostream>
using namespace std;

int main() {
  for(int i=10; i>0; --i) cout << i << endl;
  cerr << "ERROR: System timed out" << endl;
  return -1;
}
