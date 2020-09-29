#ifndef __AND_H
#define __AND_H

#include "gate.h"

class And : public Gate {
  public:
    Signal output() override;
};

#endif

