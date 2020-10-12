#ifndef __NIM_H_
#define __NIM_H_

class Nim {
  public:
    Nim(int sticks, int first_player = 1);
    Nim();                        // All options randomized
    int current_player();         // Player to move next
    int sticks_left();            // Number of sticks in pile
    void take_sticks(int sticks); // Remove sticks from pile
    int optimal_move();           // Best move to win
  private:
    int _sticks;                  // Number of sticks in pile
    int _current_player;          // Player to move next
};

#endif

