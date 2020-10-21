#include "mainwin.h"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "paint.app");
    Mainwin win;
    app->run(win);
}
