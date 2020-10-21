#include "canvas.h"
#include "line.h"

namespace Graph_lib {   // our graphics interface

Canvas::Canvas() : Gtk::DrawingArea(), dirty{false}, click_in_progress{false}, rubber_band{nullptr}, pen_color{Gdk::RGBA("blue")}, width{1} {
    add_events(Gdk::BUTTON_PRESS_MASK);   // Notify on mouse click
    add_events(Gdk::POINTER_MOTION_MASK); // Notify on mouse movement
    override_background_color(Gdk::RGBA("white"));
}

bool Canvas::saved() {
    return !dirty;
}

void Canvas::clear() {
    shapes.clear();
    dirty = false;
}

Gdk::RGBA Canvas::get_pen_color() {return pen_color;}
void Canvas::set_pen_color(Gdk::RGBA color) {pen_color = color;}

// Set and get the pen width
double Canvas::get_pen_width() {return width;}
void Canvas::set_pen_width(double new_width) {width = new_width;}


void Canvas::add_shape(Shape& shape) {
    shapes.push_back(shape.clone());
    dirty = true;
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

        // Just remember the coordinates on the first click, but
        // add a new line on the second click
        if (!click_in_progress) {
            x1 = event->x;
            y1 = event->y;
            click_in_progress = true;
        } else {
            Line line{Point{x1, y1}, 
                      Point{static_cast<int>(event->x), static_cast<int>(event->y)},
                      pen_color, width};
            add_shape(line);
            click_in_progress = false;
            delete rubber_band;
            rubber_band = nullptr;
            queue_draw();  // initiate screen refresh
        }
        return true; // We handled this event
    }
    return false;  // We did NOT handle this event
}

// Drag mouse event handler (for scribbling)
bool Canvas::on_motion_notify_event(GdkEventMotion * event) {

    // Only rubber band after the first click
    if (!click_in_progress) return false;

    int x2 = (int)event->x;
    int y2 = (int)event->y;
    // guint state = event->state;

    delete rubber_band;
    rubber_band = new Line{Point{x1, y1}, Point{x2, y2}, pen_color, width};
    queue_draw();  // initiate screen refresh
 
    return true;  // We handled this event
}

}

