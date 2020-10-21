#include "turtle.h"
#include "point.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace Graph_lib {
Turtle::Turtle(Point start, double facing, std::string program)
      : x{(double)start.x()}, y{(double)start.y()}, angle{facing}, pen_is_down{true} {
    parse(program);
}

void Turtle::parse(std::string program) {
    std::istringstream ist{program};
    std::string token;
    double value;
    int tokens = 0;
    while(ist >> token) {
        ++tokens;
        if (token == "u") penUp();
        else if (token == "d") penDown();
        else if (token == "t") {if (ist >> value) turn(value);}
        else if (token == "f") {if (ist >> value) forward(value);}
        else throw std::runtime_error("Turtle parse error at " 
            + std::to_string(tokens) + "for '" + program + "'");
    }
    std::cout << std::endl;
}

void Turtle::penUp() {pen_is_down = false; std::cout << "u";}
void Turtle::penDown() {pen_is_down = true; std::cout << "d";}
void Turtle::turn(double degrees) {angle += degrees * d2r; std::cout << "t";}
void Turtle::forward(double distance) {std::cout << "f";
  double x2 = x + distance*cos(angle);
  double y2 = y + distance*sin(angle);
  // TODO: Should be Polyline, switching to new object only on PenUp
  if (pen_is_down) lines.push_back(Line{Point{(int)x, (int)y}, Point{(int)x2, (int)y2}});
  x = x2;
  y = y2;
}

void Turtle::draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    std::cout << 'T';
    for (Line l : lines)
        l.draw(cr);
}

Turtle* Turtle::clone() {
    return new Turtle{*this}; 
}


std::ostream& operator<<(std::ostream& ost, Turtle& t) {
    for (Line& l : t.lines) {
        ost << l << ' ';
    }
    return ost;
}
}
