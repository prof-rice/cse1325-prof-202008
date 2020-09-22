#include "riddle.h"

Riddle::Riddle(std::string question) : _question{new std::string{question}}, _solution{new std::string} { }

void Riddle::add_solution(std::string solution) {
    *_solution = solution;
}

Riddle::~Riddle() {delete _question; delete _solution;}

Riddle::Riddle(const Riddle& riddle) :
    _question{new std::string{*riddle._question}},
    _solution  {new std::string{*riddle._solution}} { 
}
    
Riddle& Riddle::operator=(const Riddle& riddle) {
    if (this != &riddle) {
        delete _question; _question = nullptr;
        delete _solution;   _solution   = nullptr;
        _question = new std::string{*riddle._question};
        _solution   = new std::string{*riddle._solution};
    }
    return *this;
}

std::ostream& operator<<(std::ostream& ost, const Riddle& riddle) {
    ost << *riddle._question;
    if (riddle._solution) ost << "\n    " << *riddle._solution;
    return ost;
}
