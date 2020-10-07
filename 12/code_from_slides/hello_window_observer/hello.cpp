#include "hello.h"
#include <iostream>

Hello::Hello() : button{"Hello, World!"} {
  set_border_width(10);
  button.signal_clicked().connect(
      [this] {this->on_button_clicked();});
  add(button);
  button.show();
}

Hello::~Hello() { }

void Hello::on_button_clicked() {
  std::cout << "Hello, World!" << std::endl;
}

