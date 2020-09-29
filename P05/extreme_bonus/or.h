#ifndef __OR_H
#define __OR_H

#include "gate.h"

class Or : public Gate {
  public:
    Signal output() override;
};

#endif

