#include <iostream>
#include <vector>
using namespace std;

// WHAT IF WE DON'T KNOW???
//
// #define MAX_SIZE 11   // The C way
// const int MAX_SIZE = 11; // The C++ (or "Right") way
// constexpr int MAX_SIZE = 11; // More explicitly a compile-time constant

int main() {
  vector<int> array;  // Like an array, but can change size on the fly
  for(int i=0; i<20; ++i) array.push_back(i*i); // Append to the array
  for(auto i : array) cout << i << endl; // No index, just a stream of elements
  // Pseudo-type "auto" just means "Whatever type I stored in container 'array'"
}
