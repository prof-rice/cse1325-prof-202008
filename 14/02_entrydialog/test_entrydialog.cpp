#include "entrydialog.h"
#include <gtkmm.h>
#include <iostream>

int main (int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.entrydialog.v1_0");
    Gtk::Window win;
    EntryDialog dialog{win, "Here's a test!"};
    dialog.set_text("Testing 1 2 3...");
    dialog.run();
    std::cout << dialog.get_text() << std::endl;
}

