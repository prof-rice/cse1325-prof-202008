#include "riddle.h"

Riddle::Riddle(std::string question) 
    : _question{new std::string{question}}, // initialization list
      _solution{new std::string} { }        //   with heap allocation

void Riddle::add_solution(std::string solution) {
    *_solution = solution;
}

std::ostream& operator<<(std::ostream& ost, const Riddle& riddle) {
    ost << *riddle._question;
    // The next line is a C++ idiom for "if the pointer is not nullptr"
    if (riddle._solution) ost << "\n    " << *riddle._solution;
    return ost;
}
