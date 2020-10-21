#include "shape.h"

namespace Graph_lib {   // our graphics interface

Shape::Shape(Gdk::RGBA color, double width) : color{color}, width{width} { }

void Shape::save(std::ostream& ost) {
  ost << points.size() << ' ';
  for (Point p : points) p.save(ost);
  ost << color.to_string() << ' ' << width << ' ';
}

Shape::Shape(std::istream& ist) {
  int size;
  std::string rgba_color;

  ist >> size; // Number of points to restore
  for (int i=0; i<size; ++i) points.push_back(Point{ist});
  ist >> rgba_color >> width;
  color = Gdk::RGBA{rgba_color};
}

void Shape::add_point(Point p) {
    points.push_back(p);
}

void Shape::draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    Gdk::Cairo::set_source_rgba(cr, color);
    cr->set_line_width(width);
    int i = 0;
    for (const Point& p : points) {
        if (!i++) cr->move_to(p.x(), p.y());
        else cr->line_to(p.x(), p.y());
    }
    cr->stroke();
}
}

