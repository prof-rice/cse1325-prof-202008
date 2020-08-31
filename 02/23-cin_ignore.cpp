#include <iostream>
using namespace std;

int main() {
  string s;
  int a;
  cout << "What's your name? "; // try "George Rice"
  cin >> s;
  cin.clear();  // Clear any errors reading the string
  cin.ignore(32767, '\n');  // Ignore any text left in the input
  cout << "What's your age? ";
  cin >> a;
  cout << "Your name is " << s << " and you're " << a << " years old"<< endl;
}
