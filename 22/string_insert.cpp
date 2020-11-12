#include <iostream>

int main() {
    std::string s = "I you";
    int i = 0;
    for(char c : s) {
        s += c; 
        if (c == ' ') s +=  "love ";
        if (i++ > 64) break;
    }
    std::cout << s << std::endl;
}
