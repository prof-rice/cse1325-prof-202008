#include "gate.h"
#include <stdexcept>
#include <cassert>

Gate::Gate() : input1{0}, input2{0} { }

void Gate::connect(Gate& gate, Pin input_pin) {
    assert(to_gate.size() == to_pin.size());
    to_gate.push_back(&gate);
    to_pin.push_back(input_pin);
}

void Gate::input(Pin pin, Signal signal) {
    if(pin == 1) input1 = (signal != 0);
    else if (pin == 2) input2 = (signal != 0);
    else throw std::runtime_error{"invalid pin on input"};
    for(int i=0; i<to_gate.size(); ++i) 
        to_gate[i]->input(to_pin[i], output());
}

Signal Gate::input(Pin pin) {return (pin == 1) ? input1 : input2;}

