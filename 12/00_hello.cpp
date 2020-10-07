#include <gtkmm.h>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "test.app");
    Gtk::MessageDialog dialog{"Hello, world!"};
    dialog.run();
}
