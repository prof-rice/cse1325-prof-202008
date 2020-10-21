#ifndef __CANVAS_H
#define __CANVAS_H

#include <gtkmm.h>

class Canvas : public Gtk::DrawingArea {
  protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

#endif
