#include <iostream>

int main() {
    std::string s;
    std::cout << "Enter an int: ";
    std::cin >> s;
    int i = stoi(s);
    std::cout << "You entered: " << i << std::endl;
}
