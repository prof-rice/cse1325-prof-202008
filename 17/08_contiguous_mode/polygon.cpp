#include "polygon.h"
#include <iostream>

namespace Graph_lib {

Polygon* Polygon::clone() {
    return new Polygon{*this}; 
}

void Polygon::draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    Polyline::draw(cr); 
    cr->line_to(points[0].x(), points[0].y());
}
}
