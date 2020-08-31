#include <iostream>
using namespace std;

// #define MAX_SIZE 11   // The C way
// const int MAX_SIZE = 11; // The C++ (or "Right") way
constexpr int MAX_SIZE = 11; // More explicitly a compile-time constant

int main() {
  int array[MAX_SIZE];
  for(int i=0; i<MAX_SIZE; ++i) array[i] = i*i;
  for(int i=0; i<MAX_SIZE; ++i) cout << array[i] << endl;;
}
