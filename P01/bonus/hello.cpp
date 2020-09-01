 #include <iostream>
 using namespace std;
 int main() {
   string name;
   cout << "What's your name? ";
   cin >> name; // or getline(cin, name);
   cout << "Hello, " << name << "!" << endl;
 }
