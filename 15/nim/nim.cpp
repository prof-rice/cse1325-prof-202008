#include "nim.h"
#include <stdexcept>
#include <cstdlib>

Nim::Nim(int sticks, int first_player) 
       : _sticks{sticks}, _current_player{first_player} { }

Nim::Nim() {
  srand (time(NULL));
  _sticks = std::rand() % 9 + 7;
  _current_player = std::rand() % 2 + 1;
}

Nim::Nim(std::istream& ist) {
   ist >> _sticks >> _current_player;
   ist.ignore(32767, '\n');
}

void Nim::save(std::ostream& ost) {
    ost << _sticks << std::endl;
    ost << _current_player << std::endl;
}


int Nim::current_player() {
  return _current_player;
}

int Nim::sticks_left() {
  return _sticks;
}

void Nim::take_sticks(int sticks) {
  if (_sticks >= sticks) _sticks -= sticks;
  else throw std::runtime_error("Out of sticks!");
  if (_sticks > 0) _current_player = 3 - _current_player;
}

int Nim::optimal_move() {
  if (_sticks <= 1) return 1;
  switch(_sticks%4) {
    case 0: return 3;
    case 1: return std::rand()%3+1;
    case 2: return 1;
    case 3: return 2;
    default: throw std::runtime_error("Internal calculation error!");
  }
}  
