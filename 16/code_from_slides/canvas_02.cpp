#include "canvas.h"
#include "turtle.h"

bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    // Create a Cairomm context to manage our drawing
    Gtk::Allocation allocation = get_allocation();

    const double width = allocation.get_width();
    const double height = allocation.get_height();
    cr->translate(width / 2, height / 2);

    Turtle turtle;

    // Draw a square
    for (int i=1; i<300; i += 1) {turtle.forward(i); turtle.turn(61);}
    turtle.draw(cr);

    // Apply the colors to the window
    cr->stroke();

    // Drawing was successful
    return true;
}

