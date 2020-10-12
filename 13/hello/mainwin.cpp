#include "mainwin.h"
#include <iostream>

Mainwin::Mainwin() : button{new Gtk::Button{"Hello, world!"}} {
  add(*button);
  button->signal_clicked().connect([this] {this->on_button_click();});
                    // or .connect([] {std::cout << "Hello, world!\n";});
  button->show();
}

Mainwin::~Mainwin() { }

void Mainwin::on_button_click() {
    std::cout << "Hello, world!" << std::endl;
}
