#include "canvas.h"

bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    // Create a Cairomm context to manage our drawing
    Gtk::Allocation allocation = get_allocation();

    const double width = allocation.get_width();
    const double height = allocation.get_height();

    // Draw a square
    cr->move_to(100,       100);
    cr->line_to(width-100, 100);
    cr->line_to(width-100, height-100);
    cr->line_to(100,       height-100);
    cr->line_to(100,       100);

    // Apply the colors to the window
    cr->stroke();

    // Drawing was successful
    return true;
}

