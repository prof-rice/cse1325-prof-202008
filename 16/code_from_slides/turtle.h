#ifndef __TURTLE_H
#define __TURTLE_H

#include <gtkmm.h>
#include <cmath>
#include <vector>

class Line {
  public:
    Line(int x1, int y1, int x2, int y2) 
        : _x1{x1}, _y1{y1}, _x2{x2}, _y2{y2} { }
    int x1() {return _x1;}
    int y1() {return _y1;}
    int x2() {return _x2;}
    int y2() {return _y2;}
  private:
    int _x1, _y1, _x2, _y2;
};

class Turtle {
  public:
    Turtle();
    void penUp();
    void penDown();
    void turn(double degrees);
    void forward(double distance);
    virtual void draw(const Cairo::RefPtr<Cairo::Context>& cr);
  private:
    std::vector<Line> lines;
    const double d2r = M_PI/180.0; // Degrees to radians
    double x, y, angle; // Current turtle position
    bool pen_is_down;
};

#endif
