#include "mainwin.h"
#include "imagedialog.h"
#include <iostream>

Mainwin::Mainwin() : button{new Gtk::Button{"Hello, world!"}} {
  add(*button);
  button->signal_clicked().connect([this] {this->on_button_click();});
  button->show();
}

Mainwin::~Mainwin() { }

void Mainwin::on_button_click() {
    ImageDialog dialog{*this, "tux.png", "Created by lewing@isc.tamu.edu Larry Ewing and The GIMP, and licensed under the Creative Commons CC0 1.0 Universal Public Domain Dedication"};
    dialog.run();
}
