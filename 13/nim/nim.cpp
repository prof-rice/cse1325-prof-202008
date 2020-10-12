#include "nim.h"
#include <stdexcept>

Nim::Nim(int sticks, int first_player) 
       : _sticks{sticks}, _current_player{first_player} { }

Nim::Nim() : Nim(std::rand() % 9 + 7, std::rand() % 2 + 1) { }

int Nim::current_player() {return _current_player;}

int Nim::sticks_left() {return _sticks;}

void Nim::take_sticks(int sticks) {
  if (_sticks >= sticks) _sticks -= sticks;
  else throw std::runtime_error("Out of sticks!");
  if (_sticks > 0) _current_player = 3 - _current_player;
    // or _current_player = (_current_player == 1) ? 2 : 1;
    // or if (_current_player == 1) _current_player == 2;
    //    else _current_player == 1;
}

int Nim::optimal_move() {
  if (_sticks <= 1) return 1;
  switch(_sticks%4) {
    case 1: return std::rand()%3+1;
    case 2: return 1;
    case 3: return 2;
    case 0: return 3;
    default: throw std::runtime_error("Internal calculation error!");
  }
}  
