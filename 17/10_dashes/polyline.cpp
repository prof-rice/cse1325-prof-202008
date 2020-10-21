#include "polyline.h"
#include <iostream>

namespace Graph_lib {

Polyline::Polyline(Gdk::RGBA color, double width, int dash) : Shape(color, width, dash) { }

Polyline::Polyline(std::istream& ist) : Shape(ist) { }

Polyline* Polyline::clone() {
    return new Polyline{*this}; 
}
}
