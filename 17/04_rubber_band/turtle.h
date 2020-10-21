#ifndef __TURTLE_H
#define __TURTLE_H

#include "shape.h"
#include "point.h"
#include "line.h"

namespace Graph_lib { 
class Turtle : public Shape {
  public:
    Turtle(Point start = Point{0,0}, double facing = 0, std::string program = "");
    void parse(std::string program);
    void penUp();
    void penDown();
    void turn(double degrees);
    void forward(double distance);
    virtual void draw(const Cairo::RefPtr<Cairo::Context>& cr);
    virtual Turtle* clone() override; // Creates object copy on heap
    friend std::ostream& operator<<(std::ostream& ost, Turtle& t);
  private:
    std::vector<Line> lines;
    const double d2r = M_PI/180.0; // Degrees to radians
    double x, y, angle; // Current turtle position
    bool pen_is_down;
};
}
#endif
