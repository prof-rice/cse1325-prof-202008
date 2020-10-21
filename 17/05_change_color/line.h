#ifndef _LINE_H
#define _LINE_H
#include "shape.h"

namespace Graph_lib { 
class Line : public Shape {  // Inherits draw
   public:
     Line(Point p1, Point p2, Gdk::RGBA color);

     // Give a compiler warning if Line::add_point is called
     [[deprecated]]
     virtual void add_point(Point p);
 
     virtual Line* clone() override; // Creates object copy on heap
};
}
#endif
