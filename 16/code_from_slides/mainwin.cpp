#include "mainwin.h"
#include "canvas.h"

Mainwin::Mainwin() : canvas{new Canvas} {
  set_default_size(300, 300);
  add(*canvas);
  canvas->show();
}

Mainwin::~Mainwin() { }

