#include <gtkmm.h>
#include <iostream>

class Mainwin : public Gtk::Window {
    public:
        Mainwin();                 // Adds widgets and signals on launch
        virtual ~Mainwin();        // Deletes unmanaged widgets on window close
    protected:
        void on_button_clicked();  // To be called when button is clicked
        Gtk::Button *button;       // A button in place of the label
};

Mainwin::Mainwin() {               // Constructor adds widgets and signals
    set_default_size(180, 40);     // Set the window to 180x40 pixels
    set_title("Hello");            // Set the title bar of the window

    // Create a managed Button with centered "Hello, World!" on it
    button = Gtk::manage(new Gtk::Button{"Hello, World!"});
    add(*button);                  // Add the button widget to the window
    button->signal_clicked().connect([this] {this->on_button_clicked();});
    button->show();                // Make the button visible
}

void Mainwin::on_button_clicked() {
    std::cout << "Hello, Window!" << std::endl;
}

Mainwin::~Mainwin() { }            // Always declare a virtual destructor

int main(int argc, char* argv[]) { // Main is predictable - make an app
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.hello");
    Mainwin win;                   // Instance the Window
    return app->run(win);          // Tell the app to run the window
}
