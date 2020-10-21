#include "canvas.h"
#include "line.h"

namespace Graph_lib {   // our graphics interface

Canvas::Canvas() : Gtk::DrawingArea(), dirty{false}, click_in_progress{false} {
    add_events(Gdk::BUTTON_PRESS_MASK);  // Notify on mouse click
}

bool Canvas::saved() {
    return !dirty;
}

void Canvas::clear() {
    shapes.clear();
    dirty = false;
}

void Canvas::add_shape(Shape& shape) {
    shapes.push_back(shape.clone());
    dirty = true;
}

// Draw the lines any time gtkmm needs to refresh the widget
bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

    // If nothing to draw, we're done
    if (shapes.size() == 0) return true;

    // Create a Cairomm context to manage our drawing
    Gtk::Allocation allocation = get_allocation();

    // Center the drawing in the window
    const double width = allocation.get_width();
    const double height = allocation.get_height();

    // Use a 3 pixel wide red line
    cr->set_line_width(3.0);
    cr->set_source_rgb(0.8, 0.0, 0.0); // Set lines to red

    // Draw the lines
    for(Shape* s : shapes) {
        s->draw(cr);
    }

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
                      Point{static_cast<int>(event->x), static_cast<int>(event->y)}};
            add_shape(line);
            click_in_progress = false;
            queue_draw();  // initiate screen refresh
        }
        return true; // We handled this event
    }
    return false;  // We did NOT handle this event
}

}

