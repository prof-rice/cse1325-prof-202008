#include "line.h"
#include <cassert>

namespace Graph_lib {

Line::Line(Point p1, Point p2, Gdk::RGBA color, double width, int dash) : Shape(color, width, dash) { 
    points.push_back(p1);
    points.push_back(p2);
}
Line::Line(std::istream& ist) : Shape(ist) { }

Line* Line::clone() {
    return new Line{*this}; 
}

void Line::add_point(Point p) {
    bool invalid_call_to_Line_add_point = false;
    assert(invalid_call_to_Line_add_point);
}
}
