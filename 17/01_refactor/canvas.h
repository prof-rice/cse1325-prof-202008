#ifndef __CANVAS_H
#define __CANVAS_H

#include "shape.h"
#include <vector>

namespace Graph_lib {   // our graphics interface

class Canvas : public Gtk::DrawingArea {
  public:
    void add_shape(Shape& shape);
  protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    std::vector<Shape*> shapes;
};
}
#endif
