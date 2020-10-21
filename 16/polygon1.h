#ifndef _POLYGON_H
#define _POLYGON_H
#include "shape.h"

namespace Graph_lib { 
class Polygon : public Shape {
   public:
     virtual Polygon* clone() override; // Creates object copy on heap
     virtual void draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};
}
#endif
