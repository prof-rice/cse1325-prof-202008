#include <iostream>
#include <list>
using namespace std;

int main() {
  int i;
  // "list" is a linked list - you can push_front and insert as well as push_back
  list<int> v;

  while(cin >> i)   // Use Control-d (or Control-z on Windows) to exit loop
    v.push_front(i);
  for(auto i : v) cout << i << endl; 
}
