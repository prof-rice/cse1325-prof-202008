#include "canvas.h"

void Canvas::clear() {
    coordinates.clear(); // Delete all elements of vector coordinates
}
void Canvas::add(double x, double y) {
    coordinates.push_back(Coordinate{x, y}); // Add an x,y pair to coordinates
    // NOTE: x and y can be recovered using "structured binding", e.g., 
    //   auto&[x, y] = coordinates[0] // Recover first x,y pair
}
void Canvas::offset(double xoff, double yoff) {
    offsets = Coordinate{xoff, yoff};  // Assign x,y to offsets
    // NOTE: To recover x and y use auto&[xoff, yoff] = offsets;
}

// Draw the lines any time gtkmm needs to refresh the widget
bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    // Specify 3-pixel wide red lines
    cr->set_line_width(3.0);
    cr->set_source_rgb(0.8, 0.0, 0.0); 
    cr->set_dash(std::vector<double>{8.0, 4.0}, 0.0);

    // Draw the lines from vector coordinates
    int draw = 0;
    auto&[xoff, yoff] = offsets; 
    for(auto c : coordinates) {
        auto&[x, y] = c;
        if(draw++) cr->line_to(x + xoff, y + yoff);
        else       cr->move_to(x + xoff, y + yoff);
    }

    // Apply the colors drawn to the window
    cr->stroke();

    // Report that drawing was successful
    return true; 
}

