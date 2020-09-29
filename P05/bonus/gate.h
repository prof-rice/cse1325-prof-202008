#ifndef __GATE_H
#define __GATE_H

typedef int Pin;
typedef bool Signal;

class Gate {
  public:
    Gate();
    void connect(Gate& gate, Pin input_pin);
    void input(Pin pin, Signal signal);
    Signal input(Pin pin);
    virtual Signal output() = 0;
  protected:
    Signal input1;
    Signal input2;
  private:
    Gate* to_gate;
    Pin to_pin;
};

#endif

