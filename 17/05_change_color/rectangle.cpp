#include "rectangle.h"
#include <iostream>
#include <cassert>

namespace Graph_lib {
Rectangle::Rectangle(Point p1, Point p2) {
    points.push_back(p1);
    points.push_back(p2);
}

Rectangle::Rectangle(Point p1, int width, int height) 
      : Rectangle{p1, Point{p1.x()+width, p1.y()+height}} { }

Rectangle* Rectangle::clone() {
    return new Rectangle{*this}; 
}

void Rectangle::add_point(Point p) {
    bool invalid_call_to_Rectangle_add_point = false;
    assert(invalid_call_to_Rectangle_add_point);
}

void Rectangle::draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    std::cout << 'R';
    cr->move_to(points[0].x(), points[0].y());
    cr->line_to(points[0].x(), points[1].y());
    cr->line_to(points[1].x(), points[1].y());
    cr->line_to(points[1].x(), points[0].y());
    cr->line_to(points[0].x(), points[0].y());
}
}
