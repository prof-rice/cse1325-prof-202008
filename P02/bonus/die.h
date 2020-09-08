#ifndef __DIE_H
#define __DIE_H

class Die {
  public:
    Die(int faces);    // constructor
    const int faces(); // (getter) returns # faces set by constructor
    void roll();       // roll the die, which sets _value
    int value();       // return most recent die roll (_value)
  private:
    const int _faces;  // number of faces on this die
    int _value;        // value of the most recent die roll
};

#endif

