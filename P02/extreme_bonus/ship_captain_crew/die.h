#ifndef __DIE_H
#define __DIE_H

class Die {
  public:
    Die(int faces);
    const int faces();
    void roll();
    int value();
    void keep(bool k);
    bool keep();
  private:
    const int _faces;
    int _value;
    bool _keep;
};

#endif

