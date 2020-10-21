#ifndef __FUNCTION_H
#define __FUNCTION_H

#include "shape.h"

namespace Graph_lib { 
typedef double Fct(double);

// Plots count points of function f from x_first to x_last,
//   multiplying each x and y by xscale and yscale respectively 
class Function : public Shape {
  public:
    Function(Fct f, Point origin, double x_first, double x_last, 
        int count = 100, double xscale = 25, double yscale = 25);
    virtual Function* clone() override; // Creates object copy on heap    
};
}
#endif
