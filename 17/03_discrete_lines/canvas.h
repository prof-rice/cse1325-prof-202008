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
    bool on_button_press_event(GdkEventButton * event) override;

    std::vector<Shape*> shapes;
    bool dirty;

    bool click_in_progress; // True if first coordinate selected
    int x1, y1;             // First coordinate if click_in_progress
};
}
#endif
