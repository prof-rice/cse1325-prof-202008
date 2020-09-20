#ifndef __RIDDLE_H
#define __RIDDLE_H

#include <ostream>

class Riddle {
  public:
    Riddle(std::string question);
    void add_solution(std::string solution);
    friend std::ostream& operator<<(std::ostream& ost, const Riddle& riddle);
  private:
    std::string* _question; // Note the pointers
    std::string* _solution; // These will be on the heap (operator new)
};
#endif
