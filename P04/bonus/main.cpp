#include "riddle.h"
#include <iostream>
#include <vector>
typedef std::vector<Riddle>::size_type vt;
// g++ will complain about using an int as an index to std::vector::at
//   This typedef enables concise casting.

// Returns an int from a slightly custom prompt
int pick_a_riddle(std::string prompt = "The") {
    std::string s;
    while(true) {
       std::cout << prompt << " riddle number: ";
       try {
           std::getline(std::cin, s);
           return std::stoi(s);
       } catch(std::exception& e) {
           std::cerr << "That's not an integer!\n";
       }
    }
}

// Reads a string and adds as solution to the riddle
void solve_a_riddle(Riddle& riddle) {
    std::cout << "Solution: ";
    std::string s;
    std::getline(std::cin, s);    
    riddle.add_solution(s);
}

int main() {
    std::vector<Riddle> riddles;

    // R"( begins and )" ends a 'raw string'
    // All punctuation (including \n) is ignored
    const std::string title = R"(

==================================
   R I D D L E   M E   T H I S
==================================

)";
    const std::string menu = R"(

1) Ask a riddle
2) Answer a riddle
3) Add another answer to a riddle
4) Copy a riddle
0) Exit

Riddle me this: )";

    std::string s;

    while(true) {
        try {
            std::cout << title;
            for(int i=0; i<riddles.size(); ++i) 
                std::cout << i << ") " << riddles[i] << '\n';
            std::cout << menu;
            std::getline(std::cin, s);    
            if (s == "0") break;
            else if (s == "1") {
                std::cout << "New riddle: ";
                std::getline(std::cin, s);    
                riddles.push_back(Riddle{s});
            } else if (s == "2") {
                solve_a_riddle(riddles.at((vt)pick_a_riddle()));
            } else if (s == "3") {  // copy constructor test
                riddles.push_back(riddles.at((vt)pick_a_riddle()));
                solve_a_riddle(riddles.back());
            } else if (s == "4") {  // copy assignment operator= test
                riddles.at((vt)pick_a_riddle("To")) = riddles.at((vt)pick_a_riddle("From"));
            }
        } catch(std::exception& e) {    
            std::cerr << e.what() << "\n Invalid answer!\n";
        }
    }
}
