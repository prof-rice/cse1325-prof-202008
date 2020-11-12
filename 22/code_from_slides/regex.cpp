#include <iostream>
#include <regex>

int main() {
    std::string input;
    std::regex integer{"-?\\d+"};
    std::cout << "Enter some integers (Ctrl-d to exit):" << std::endl;

    while(std::cin>>input) {
        if(std::regex_match(input,integer)) std::cout << input << " is an int!" << std::endl;
        else std::cerr << "INVALID INPUT: " << input << std::endl;
    }
}
