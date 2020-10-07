#include "02_mainwin.h"

Mainwin::Mainwin() : button{new Gtk::Button{"Hello, world!"}} {
  add(*button);
  button->show();   
}

Mainwin::~Mainwin() { }
