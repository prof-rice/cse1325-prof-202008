#ifndef __CANVAS_H
#define __CANVAS_H

#include "shape.h"
#include <vector>

namespace Graph_lib {   // our graphics interface

class Canvas : public Gtk::DrawingArea {
  public:
    Canvas();
    void add_shape(Shape& shape);
    bool saved(); // true if all data has been saved
    void clear(); // clear all drawings from the canvas
  protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    std::vector<Shape*> shapes;
    bool dirty;
};
}
#endif
