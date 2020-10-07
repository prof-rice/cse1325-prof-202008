#include <gtkmm.h>

class Mainwin : public Gtk::Window {
    public:
        Mainwin();                 // Adds widgets and signals on launch
        virtual ~Mainwin();        // Deletes unmanaged widgets on window close
    protected:
        Gtk::Label *msg;           // Text display
};

Mainwin::Mainwin() {               // Constructor adds widgets and signals
    set_default_size(180, 40);     // Set the window to 180x40 pixels
    set_title("Hello");            // Set the title bar of the window

    // Create a managed Label with centered "Hello, World!" on it
    msg = Gtk::manage(new Gtk::Label{"Hello, World!", Gtk::ALIGN_CENTER});
    add(*msg);                     // Add the label widget to the window
    msg->show();                   // Make the label visible
}


Mainwin::~Mainwin() { }            // Always declare a virtual destructor

int main(int argc, char* argv[]) { // Main is predictable - make an app
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.hello");
    Mainwin win;                   // Instance the Window
    return app->run(win);          // Tell the app to run the window
}
