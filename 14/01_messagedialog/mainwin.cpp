#include "mainwin.h"

Mainwin::Mainwin() : button{new Gtk::Button{"Hello, world!"}} {
  add(*button);
  button->signal_clicked().connect([this] {this->on_button_click();});
  button->show();
}

Mainwin::~Mainwin() { }

void Mainwin::on_button_click() {
    Gtk::MessageDialog{*this, "Ouch!"}.run();  // Concise message dialog!
}
