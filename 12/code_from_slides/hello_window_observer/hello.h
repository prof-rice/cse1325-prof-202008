#ifndef _HELLO_H
#define _HELLO_H

#include <gtkmm.h>

class Hello : public Gtk::Window {
  public:
    Hello();
    virtual ~Hello();
  protected:
    void on_button_clicked();
    Gtk::Button button;
};
#endif

