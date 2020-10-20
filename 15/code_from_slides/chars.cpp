#include <iostream>

int main() {
    char ch;
    std::cout << "(1) cin>> or (2) cin.get? ";
    std::cin >> ch;
    std::cin.ignore();
    if (ch == '1') for ( ; std::cin>>ch     && ch != 'x'; ) std::cout << ch;
    else           for ( ; std::cin.get(ch) && ch != 'x'; ) std::cout << ch;
    std::cout << std::endl;
    return 0;
}
