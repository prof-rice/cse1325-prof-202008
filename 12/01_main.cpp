#include "01_mainwin.h"

int main(int argc, char* argv[]) { // Main is predictable - make an app
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.hello");
    Mainwin win;                   // Instance the Window
    return app->run(win);          // Tell the app to run the window
}
