#include <gtkmm.h>

class Mainwin : public Gtk::Window {
    public:
        Mainwin();                 // Adds widgets and signals on launch
        virtual ~Mainwin();        // Deletes unmanaged widgets on window close
    protected:
        Gtk::Label *msg;           // Text display
};

