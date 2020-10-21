#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "shape.h"

namespace Graph_lib { 
class Rectangle : public Shape {
   public:
     Rectangle(Point p1, Point p2);
     Rectangle(Point p1, int width, int height);
     virtual Rectangle* clone() override; // Creates object copy on heap

     // Give a compiler warning if Rectangle::add_point is called
     [[deprecated]]
     virtual void add_point(Point p);

     virtual void draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};
}
#endif
