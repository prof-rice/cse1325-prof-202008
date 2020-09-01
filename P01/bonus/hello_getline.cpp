 #include <iostream>
 using namespace std;
 int main() {
   string name;
   cout << "What's your name? ";
   getline(cin, name);
   cout << "Hello, " << name << "!" << endl;
   return 0;
 }
