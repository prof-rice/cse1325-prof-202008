#include "shape.h"

namespace Graph_lib {   // our graphics interface

void Shape::add_point(Point p) {
    points.push_back(p);
}

void Shape::draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    int i = 0;
    for (const Point& p : points)
        if (!i++) cr->move_to(p.x(), p.y());
        else cr->line_to(p.x(), p.y());
}
}

