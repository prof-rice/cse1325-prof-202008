#include <iostream>

int main() {
    std::string s;
    std::cout << "Enter an int: ";
    std::cin >> s;
    try {
        int i = stoi(s);
        std::cout << "You entered: " << i << std::endl;
    } catch (std::exception& e) { // Note the &
        std::cerr << "Exception: " << e.what() << std::endl;
        throw;
    }
}
