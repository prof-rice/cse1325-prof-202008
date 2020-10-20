#ifndef __TOOL_H
#define __TOOL_H

#include "product.h"

class Tool : public Product {
  public:
    Tool(std::string name, double price, std::string description);
};

#endif
