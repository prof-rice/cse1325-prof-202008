#include "turtle.h"

Turtle::Turtle() : x{0}, y{0}, angle{0}, pen_is_down{true} { }

void Turtle::penUp() {pen_is_down = false;}
void Turtle::penDown() {pen_is_down = true;}
void Turtle::turn(double degrees) {angle += degrees * d2r;}
void Turtle::forward(double distance) {
  double x2 = x + distance*cos(angle);
  double y2 = y + distance*sin(angle);
  if (pen_is_down) lines.push_back(Line{(int)x, (int)y, (int)x2, (int)y2});
  x = x2;
  y = y2;
}

void Turtle::draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    for (Line l : lines) {
        cr->move_to(l.x1(), l.y1());
        cr->line_to(l.x2(), l.y2());
    }
}

