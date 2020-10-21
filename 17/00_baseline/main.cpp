#include "canvas.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "rectangle.h"
#include "function.h"
#include "dfunction.h"
#include "turtle.h"
#include <gtkmm.h>
#include <iostream>
#include <cmath>

double sloping_cos(double x) { return cos(x)+x/3.14; }

// Spirograph equations courtesy of Linux Gazette, https://linuxgazette.net/133/luana.html
double fx(double R, double r, double p, double t) {return (double)((R-r)*cos(t)+p*cos((R-r)*t/r));}
double fy(double R, double r, double p, double t) {return (double)((R-r)*sin(t)+p*sin((R-r)*t/r));}


int main(int argc, char** argv) {
   // Create the application
   auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.shapes");

   // Instance a window
   Gtk::Window win;
   win.set_title("Shapes");
   win.set_default_size(800, 600);

   // Add a drawing area
   Graph_lib::Canvas c;
   win.add(c);
   c.show();

   // Create the drawing using shapes
   Graph_lib::Polyline s;
   s.add_point(Graph_lib::Point{-10,-10});
   s.add_point(Graph_lib::Point{10,10});
   c.add_shape(s);
   std::cout << "Polyline part of X " << s << std::endl;

   // Test a polygon
   Graph_lib::Polygon p;
   p.add_point(Graph_lib::Point{0,-50});
   p.add_point(Graph_lib::Point{100,-50});
   p.add_point(Graph_lib::Point{100,-100});
   p.add_point(Graph_lib::Point{0,-100});
   p.add_point(Graph_lib::Point{-25,-75});
   c.add_shape(p);
   std::cout << "Polygon " << p << std::endl;

   Graph_lib::Rectangle r1{Graph_lib::Point{-150,-100}, 100, 50};
   // r1.add_point(Graph_lib::Point{-25,-75}); // Generates compiler warning and runtime abort
   c.add_shape(r1);
   std::cout << "Rectangle w/width & height " << r1 << std::endl;

   Graph_lib::Rectangle r2{Graph_lib::Point{-150,100}, Graph_lib::Point{-50,50}};
   c.add_shape(r2);
   std::cout << "Rectangle w/2 points " << r2 << std::endl;

   // Test a line
   Graph_lib::Line l{Graph_lib::Point{-10,10}, {10, -10}};
   c.add_shape(l);
   std::cout << "Line part of X " << l << std::endl;

   // Graph some functions (mostly with lambdas)
   Graph_lib::Function f{cos, Graph_lib::Point{-250,0}, 0.0, 3.14*6, 160, 25, 25};
   c.add_shape(f);
   std::cout << "Function cos " << f << std::endl;

   // Graph_lib::Function fs{sloping_cos, Graph_lib::Point{-250,0}, 0.0, 3.14*6, 160, 25, 25};
   Graph_lib::Function fs{[](double x) {return cos(x)+x/3.14;}, Graph_lib::Point{-250,0}, 0.0, 3.14*6, 160, 25, 25};
   c.add_shape(fs);
   std::cout << "Function sloping cos" << fs << std::endl;

   Graph_lib::Function fm{[ ] (double x) {return fmod(x, 16.0);}, Graph_lib::Point{-250,-200}, 0.0, 3.14*30, 160, 5, 5};
   c.add_shape(fm);
   std::cout << "Function fmod " << fm << std::endl;

   Graph_lib::Function fr{[ ] (double x) {return (double)rand() / RAND_MAX;}, Graph_lib::Point{-250,-50}, 0.0, 3.14*6, 160, 25, 25};
   c.add_shape(fr);
   std::cout << "Function rand() " << fr << std::endl;

   Graph_lib::Dfunction ft{[](double t){double s = sin(t/180); double c = cos(t/150); return s*c+2*c-2*s;}, 
                           [](double t){double s = sin(t/310); double c = cos(t/180); return 3*s-3*c;}, 
                               Graph_lib::Point{300,300}, 0.0, 3.14*3600, 4001, 20, 20};
   c.add_shape(ft);
   std::cout << "Double function (Trig)" << ft << std::endl;

   Graph_lib::Dfunction fd{[](double t){return fx(100,2,80,t);}, 
                           [](double t){return fy(100,2,80,t);}, 
                               Graph_lib::Point{-300,300}, 0.0, 3.14*2, 2001, 1, 1};
   c.add_shape(fd);
   std::cout << "Double function (Spirograph™)" << fd << std::endl;

   std::string tt = "d f 25 t 30 u f 25 t 30 ";
   Graph_lib::Turtle t{Graph_lib::Point{50,150}, 0, tt + tt + tt + tt + tt};
   t.penDown(); t.forward(25);
   c.add_shape(t);
   std::cout << "Turtle " << t << std::endl;

   // Give control to gtkmm
   return app->run(win);
}
