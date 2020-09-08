#ifndef __DIE_H
#define __DIE_H

class Die {
  public:
    Die(int faces);
    int faces();
    int roll();
  private:
    int _faces;
};

#endif

