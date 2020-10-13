#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>

Mainwin::Mainwin() : button{new Gtk::Button{"Hello, world!"}} {
  add(*button);
  button->signal_clicked().connect([this] {this->on_button_click();});
  button->show();
}

Mainwin::~Mainwin() { }

void Mainwin::on_button_click() {
    EntryDialog edialog{*this, "<big>EntryDialog Demo</big>", true};
    edialog.set_secondary_text("What <i>shall</i> we display <b>today</b>?", true);
    edialog.set_text("Nothing to report...");
    edialog.run();

    Gtk::MessageDialog mdialog{*this, edialog.get_text()};
    mdialog.run();
}
