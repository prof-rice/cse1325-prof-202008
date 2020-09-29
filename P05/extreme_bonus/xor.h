#ifndef __XOR_H
#define __XOR_H

#include "gate.h"

class Xor : public Gate {
  public:
    Signal output() override;
};

#endif

