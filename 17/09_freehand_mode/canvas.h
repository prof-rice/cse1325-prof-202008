#ifndef __CANVAS_H
#define __CANVAS_H

#include "shape.h"
#include <vector>

namespace Graph_lib {   // our graphics interface

enum class Penmode {SEGMENT, CONTIGUOUS, FREEHAND};

class Canvas : public Gtk::DrawingArea {
  public:
    Canvas();
    
    // Manage file I/O
    std::string get_filename();
    void set_filename(std::string filename);
    void clear(); // clear all drawings from the canvas
    bool saved(); // true if all data has been saved
    void save(std::ostream& ost);
    void load(std::istream& ist);

    void set_penmode(Penmode mode);
    Penmode get_penmode();

    Gdk::RGBA get_pen_color();
    void set_pen_color(Gdk::RGBA color);

    void set_pen_width(double new_width);
    double get_pen_width();
  protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    bool on_button_press_event(GdkEventButton * event) override;
    bool on_motion_notify_event(GdkEventMotion * event) override;

    void add_shape(Shape& shape);            // to painting, cloned
    void add_point(Graph_lib::Point& point); // to most recently added shape

    std::string filename;       // The filename in which this painting is saved
    std::vector<Shape*> shapes; // All of the shapes making up this painting
    Shape* rubber_band;         // The rubber band shape
    bool dirty;

    Penmode penmode;          // Which shape we're drawing
    Penmode previous_penmode; // If Penmode changes, we're done with previous shape
    int click_in_progress;    // Number of coordinates selected
    int x1, y1;               // First coordinate if click_in_progress
    Gdk::RGBA pen_color;      // Color for subsequent shapes
    double width;             // Line width for subsequent shapes
};
}
#endif
