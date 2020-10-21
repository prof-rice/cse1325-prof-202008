#ifndef _POLYLINE_H
#define _POLYLINE_H
#include "shape.h"

namespace Graph_lib { 
class Polyline : public Shape {
   public:
     Polyline(Gdk::RGBA color, double width, int dash);
     Polyline(std::istream& ist);
     virtual Polyline* clone() override; // Creates object copy on heap
};
}
#endif
