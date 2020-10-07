#include "01_mainwin.h"

Mainwin::Mainwin() {               // Constructor adds widgets and signals
    set_default_size(180, 40);     // Set the window to 180x40 pixels
    set_title("Hello");            // Set the title bar of the window

    // Create a managed Label with centered "Hello, World!" on it
    msg = Gtk::manage(new Gtk::Label{"Hello, World!", Gtk::ALIGN_CENTER});
    add(*msg);                     // Add the label widget to the window
    msg->show();                   // Make the label visible
}


Mainwin::~Mainwin() { }            // Always declare a virtual destructor


