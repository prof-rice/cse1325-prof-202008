#ifndef __SHAPE_H
#define __SHAPE_H

#include "point.h"
#include <vector>
#include <gtkmm.h>

namespace Graph_lib {   // our graphics interface
// A shape holds points connected by lines
class Shape {
  public:
    // This method copies the current object onto the heap and 
    // returns a pointer to it. This builds our vector of pointers 
    // to objects derived from Shape, to polymorphically call draw().
    virtual Shape* clone() = 0;

    // Appends a new point to the shape
    virtual void add_point(Point p);

    // Draws the shape (called from gtkmm's on_draw method)  
    virtual void draw(const Cairo::RefPtr<Cairo::Context>& cr);

    // Output stream shows the points that comprise the shape
    friend std::ostream& operator<<(std::ostream& ost, Shape& s);
  protected:
    std::vector<Point> points;
};
}
#endif
