#include <iostream>
#include <regex>

int main() {
    std::string input;
    std::regex integer{"-?\\d+"};
    std::cout << "Enter some integers (Ctrl-d to exit):" << std::endl;

    while(std::cin>>input) {
        if(regex_match(input,integer)) std::cout << "That’s an int!" << std::endl;
        else std::cout << "***INVALID INPUT***" << std::endl;
    }
}
