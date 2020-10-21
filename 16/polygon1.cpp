#include "polygon.h"
#include <iostream>

namespace Graph_lib {

Polygon* Polygon::clone() {
    return new Polygon{*this}; 
}

void Polygon::draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    std::cout << 'D';
    if (points.empty()) return;
    int i = 0;
    for (const Point& p : points) {
        if (!i++) cr->move_to(p.x(), p.y());
        else cr->line_to(p.x(), p.y());
    }
    cr->line_to(points[0].x(), points[0].y());
}
}
