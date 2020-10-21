#include "polyline.h"
#include <iostream>

namespace Graph_lib {

Polyline* Polyline::clone() {
    return new Polyline{*this}; 
}
}
