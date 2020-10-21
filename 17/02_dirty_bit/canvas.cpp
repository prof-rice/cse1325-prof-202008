#include "canvas.h"

namespace Graph_lib {   // our graphics interface

Canvas::Canvas() : dirty{true} { }

void Canvas::add_shape(Shape& shape) {
    shapes.push_back(shape.clone());
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
    cr->translate(width / 2, height / 2);

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

bool Canvas::saved() {
    return !dirty;
}

void Canvas::clear() {
    shapes.clear();
    dirty = false;
}
}

