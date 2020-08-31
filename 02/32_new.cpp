#include <iostream>
using namespace std;

int main() {
  // A "normal" variable is stored on the "stack"
  //    Stack variables exist until out of scope
  // We can instead store a variable on the "heap"
  //    Heap variables are created using "new" (similar to malloc)
  //    Heap variables exist until we explicitly "delete" them (similar to free)
  //    or the program itself exits
  string* sp = new string{"Beep beep"};
  cout << "sp is " << sp << endl;
  cout << "*sp is " << *sp << endl;
  cout << "*sp has " << sp->size() << " characters" << endl;
  delete sp;  // Release the heap memory allocated by "new" above
}
