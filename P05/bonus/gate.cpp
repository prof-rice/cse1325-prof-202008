#include "gate.h"
#include <stdexcept>

Gate::Gate() : input1{0}, input2{0}, to_gate{nullptr}, to_pin{1} { }

void Gate::connect(Gate& gate, Pin input_pin) {
    to_gate = &gate;
    to_pin = input_pin;
}

void Gate::input(Pin pin, Signal signal) {
    if(pin == 1) input1 = (signal != 0);
    else if (pin == 2) input2 = (signal != 0);
    else throw std::runtime_error{"invalid pin on input"};
    if(to_gate) to_gate->input(to_pin, output());
}

Signal Gate::input(Pin pin) {return (pin == 1) ? input1 : input2;}

