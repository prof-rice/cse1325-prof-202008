#include "canvas.h"
#include "line.h"
#include "polyline.h"
#include "point.h"

namespace Graph_lib {   // our graphics interface

Canvas::Canvas() : Gtk::DrawingArea(), filename{"untitled.ctp"}, dirty{false}, 
        penmode{Penmode::SEGMENT}, previous_penmode{Penmode::SEGMENT},
        click_in_progress{false}, rubber_band{nullptr}, 
        pen_color{Gdk::RGBA("blue")}, width{1}, dash{0} {
    add_events(Gdk::BUTTON_PRESS_MASK);   // Notify on mouse click
    add_events(Gdk::POINTER_MOTION_MASK); // Notify on mouse movement
    override_background_color(Gdk::RGBA("white"));
}

std::string Canvas::get_filename() {return filename;}
void Canvas::set_filename(std::string filename) {this->filename = filename;}

void Canvas::clear() {
    shapes.clear();
    dirty = false;
    queue_draw();  // Now update the display with the (lack of) data
}

bool Canvas::saved() {
    return !dirty;
}

void Canvas::save(std::ostream& ost) {
  for (Graph_lib::Shape* s : shapes) {
      ost << typeid(*s).name() << ' '; // Write the name of the actual type
      s->save(ost);
      ost << std::endl;  // one line per shape (this is ignored when loading)
  }
  dirty = false;
}
void Canvas::load(std::istream& ist) {
    bool was_dirty = (shapes.size() > 0);
    while(ist) {
        std::string typetag;
        ist >> typetag;
        if (typetag == "N9Graph_lib4LineE") {
            Line l{ist}; 
            add_shape(l);
        }
        if (typetag == "N9Graph_lib8PolylineE") {
            Polyline p{ist};
            add_shape(p);
        }
    }
    dirty = was_dirty;
    queue_draw();  // Now update the display with the new data
}

void Canvas::set_penmode(Penmode mode) {penmode = mode;}
Penmode Canvas::get_penmode() {return penmode;}

Gdk::RGBA Canvas::get_pen_color() {return pen_color;}
void Canvas::set_pen_color(Gdk::RGBA color) {pen_color = color;}

// Set and get the pen width
double Canvas::get_pen_width() {return width;}
void Canvas::set_pen_width(double new_width) {width = new_width;}

void Canvas::set_pen_dash(int new_dash) {dash = new_dash;}
int Canvas::get_pen_dash() {return dash;}

void Canvas::add_shape(Shape& shape) {
    shapes.push_back(shape.clone());
    dirty = true;
}

void Canvas::add_point(Graph_lib::Point& point) {
    if (shapes.empty()) throw std::runtime_error{"Attempted to add point to empty shapes vector"};
    shapes.back()->add_point(point);
}

// Draw the lines any time gtkmm needs to refresh the widget
bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

    // If nothing to draw, we're done
    if (!rubber_band && shapes.size() == 0) return true;

    // Create a Cairomm context to manage our drawing
    // Gtk::Allocation allocation = get_allocation();

    // Center the drawing in the window
    // const double width = allocation.get_width();
    // const double height = allocation.get_height();

    // Use a 3 pixel wide red line
    cr->set_line_width(3.0);
    cr->set_source_rgb(0.8, 0.0, 0.0); // Set lines to red

    // Draw the lines
    for(Shape* s : shapes) {
        s->draw(cr);
    }
    if (rubber_band) rubber_band->draw(cr);

    // Apply the colors to the window
    cr->stroke();

    // Drawing was successful
    return true; 
}

// Called when mouse button is clicked
bool Canvas::on_button_press_event(GdkEventButton * event) {

    // If this is a left-mouse button press, we're interested!
    if( (event->type == GDK_BUTTON_PRESS) && (event->button == 1)) {

        // If penmode changed, terminate any line drawing in progress
        if (penmode != previous_penmode) click_in_progress = 0;

        // Just remember the coordinates on the first click, but
        // add a new line on the second and (if not segments) later clicks
        if (click_in_progress == 0) {  // First click
            x1 = event->x;
            y1 = event->y;
            ++click_in_progress;
        } else {
            delete rubber_band;
            rubber_band = nullptr;
            int x2 = event->x;
            int y2 = event->y;
            Point p1{x1, y1};
            Point p2{x2, y2};
            if (p1 == p2) { // Shape completed
                click_in_progress = 0;
            } else {
                if (penmode == Penmode::SEGMENT) {
                    Line line{p1, p2, pen_color, width, dash};
                    add_shape(line);
                    click_in_progress = 0;
                } else if (penmode == Penmode::CONTIGUOUS) {
                    if (click_in_progress++ == 1) { // 1st segment - create Polyline
                        Polyline polyline{pen_color, width, dash};
                        polyline.add_point(p1);
                        add_shape(polyline);
                    }
                    add_point(p2); // to most recently added shape
                    x1 = x2; // for rubber banding
                    y1 = y2;
                }
            }
        }
        previous_penmode = penmode;
        queue_draw();  // Update the display
        return true; // We handled this event
    }
    return false;  // We did NOT handle this event
}

// Drag mouse event handler (for scribbling)
bool Canvas::on_motion_notify_event(GdkEventMotion * event) {
    int x2 = event->x;
    int y2 = event->y;
    Point p1{x1,y1};
    Point p2{x2,y2};

    if (penmode == Penmode::FREEHAND) {  // draw freehand
        if (penmode != previous_penmode) click_in_progress = 0;
        guint state = event->state;

        // If the button is down, add points to the Polyline
        if (state & Gdk::BUTTON1_MASK) {
            if (click_in_progress++ == 1) { // 1st segment - create Polyline
                Polyline polyline{pen_color, width, dash};
                polyline.add_point(p1);
                add_shape(polyline);
            }
            add_point(p2); // to most recently added shape
            queue_draw();  // initiate screen refresh
        // If not, signal a new Polyline is pending the next button press
        } else {
            click_in_progress = 0;
        }
        // Always track the cursor in freehand mode
        x1 = x2;
        y1 = y2;
        previous_penmode = penmode;

    } else {  // rubber band

        // Only rubber band after the first click
        if (click_in_progress == 0) return false;

        delete rubber_band;
        rubber_band = new Line{p1, p2, pen_color, width, dash};
        queue_draw();  // initiate screen refresh
    }
 
    return true;  // We handled this event
}

}

