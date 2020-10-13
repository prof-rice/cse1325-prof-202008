#include "mainwin.h"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.dialog.custom");
    Mainwin win;
    app->run(win);
}
