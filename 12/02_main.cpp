#include "02_mainwin.h"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "test.app");
    Mainwin win;
    app->run(win);
}
