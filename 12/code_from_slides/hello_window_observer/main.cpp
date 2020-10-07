#include "hello.h"
#include <gtkmm.h>

int main (int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = 
    Gtk::Application::create(argc, argv, "edu.uta.cse1325.example");
  // NOT Gtk::Main kit(argc, argv);

  // Instance a Window
  Hello hello;

  //Show the window and return when it is closed or hidden,
  //  NOT when a widget is activated (that results in an event)
  return app->run(hello);
}

