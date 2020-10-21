#include "canvas.h"

bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    // Draw a square
    cr->move_to(100, 100);
    cr->line_to(200, 100);
    cr->line_to(200, 200);
    cr->line_to(100, 200);
    cr->line_to(100, 100);

    // Apply the colors to the window
    cr->stroke();

    // Drawing was successful
    return true;
}

