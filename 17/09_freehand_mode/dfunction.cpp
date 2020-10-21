#include "dfunction.h"
#include "point.h"

namespace Graph_lib { 
Dfunction::Dfunction(Fct fx, Fct fy, Point origin, double x_first, double x_last, 
        int count, double xscale, double yscale) {
    double x = x_first;
    double delta = (x_last - x_first) / count;
    for (int i = 0; i < count; ++i) {
        points.push_back(Point{(int)(origin.x() + fx(x)*xscale), (int)(origin.y() + fy(x)*yscale)});
        x += delta;
    }
}

Dfunction* Dfunction::clone() {
    return new Dfunction{*this}; 
}
}
