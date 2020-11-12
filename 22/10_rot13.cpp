#include <iostream>

void rot13(std::string& s) {
    std::string key = "nopqrstuvwxyzabcdefghijklm";

    for(char& c : s) {
       if(c == ' ') continue;
       if(!isalpha(c)) throw std::runtime_error{"Invalid char: " + std::string{c}};
       if(islower(c)) c = key[c-'a'];
       else c = toupper(key[tolower(c)-'a']);
    }
}

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);
    try {
        rot13(s);
        std::cout << s << std::endl;
    } catch (std::exception& e) { 
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
