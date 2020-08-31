#include <iostream>
using namespace std;

int main() {
  // Some types such as string have functions "built in"
  // Here we ask the string named s its size (how many chars it has)
  string s = "What's up, Doc?";
  cout << "s is " << s << endl;
  cout << "s has " << s.size() << " characters" << endl;

  // A reference works just like a variable - it's just an aliase
  string& sr = s;
  cout << "sr is " << sr << endl;
  cout << "sr has " << sr.size() << " characters" << endl;

  // A pointer is a bit more complicated
  // Note in particular that we use "->" to access a pointer's "built in" functions
  string* sp = &s;
  cout << "*sp is " << *sp << endl;
  cout << "*sp has " << sp->size() << " characters" << endl;
}
