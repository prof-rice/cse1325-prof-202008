#include <iostream>
#include <list>
using namespace std;

void increment(int& i, int j=1, bool add=true) {
  // Same as "if (add) i += j; else i -= j;", just shorter
  i += (add ? j : -j);
}

int main() {
  int i;
  // "list" is a linked list - you can push_front and insert as well as push_back
  list<int> v;

  while(cin >> i) {  // Use Control-d (or Control-z on Windows) to exit loop
    increment(i);          // This calls the increment function with defaults
    increment(i,5, false); // This calls the increment function explicitly
    v.push_front(i);       // This reverses the numbers entered
  }
  for(auto i : v) cout << i << endl; 
}
