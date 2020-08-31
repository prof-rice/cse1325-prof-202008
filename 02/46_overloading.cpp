#include <iostream>
#include <list>
using namespace std;

void increment(int& i) {
  ++i;
}

void increment(int& i, int j) {
  i += j;
}

int main() {
  int i;
  // "list" is a linked list - you can push_front and insert as well as push_back
  list<int> v;

  while(cin >> i) {  // Use Control-d (or Control-z on Windows) to exit loop
    increment(i,5); // This calls the second, overloaded increment function
    v.push_front(i);
  }
  for(auto i : v) cout << i << endl; 
}
