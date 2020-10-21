#ifndef __DFUNCTION_H
#define __DFUNCTION_H

#include "shape.h"

namespace Graph_lib { 
typedef double Fct(double);

// Plots count points of functions (fx, fy) from x_first to x_last,
//   multiplying each x and y by xscale and yscale respectively 
class Dfunction : public Shape {
  public:
    Dfunction(Fct fx, Fct fy, Point origin, double x_first, double x_last, 
        int count = 100, double xscale = 25, double yscale = 25);
    virtual Dfunction* clone() override; // Creates object copy on heap    
};
}
#endif
