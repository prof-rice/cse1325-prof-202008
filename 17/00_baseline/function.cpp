#include "function.h"
#include "point.h"

namespace Graph_lib { 
Function::Function(Fct f, Point origin, double x_first, double x_last, 
        int count, double xscale, double yscale) {
    double x = x_first;
    double delta = (x_last - x_first) / count;
    for (int i = 0; i < count; ++i) {
        points.push_back(Point{(int)(origin.x() + x*xscale), (int)(origin.y() + f(x)*yscale)});
        x += delta;
    }
}

Function* Function::clone() {
    return new Function{*this}; 
}
}
