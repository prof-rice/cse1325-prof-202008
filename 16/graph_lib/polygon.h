#ifndef _POLYGON_H
#define _POLYGON_H
#include "polyline.h"

namespace Graph_lib { 
class Polygon : public Polyline {
   public:
     virtual Polygon* clone() override; // Creates object copy on heap
     virtual void draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};
}
#endif
