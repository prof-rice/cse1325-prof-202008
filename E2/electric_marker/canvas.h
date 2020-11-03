#ifndef __CANVAS_H
#define __CANVAS_H

#include <gtkmm.h>
#include <vector>

typedef std::pair<double, double> Coordinate;
// Construct with an x and y, e.g., Coordinate coordinate{x, y};
// Recover x and y with, e.g., auto& [x, y] = coordinate;

class Canvas : public Gtk::DrawingArea {
    public:
        void clear();  // Clear all coordinates
        void add(double x, double y);          // Add a coordinate
        void offset(double xoff, double yoff); // Add to all coordinates when drawing
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    private:
        std::vector<Coordinate> coordinates; // Store x,y pairs to draw
        Coordinate offsets;  // Add to each coordinate when drawing
};

#endif

