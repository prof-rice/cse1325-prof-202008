#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_entry_activate();
  private:
    Gtk::Entry* entry;
};

Mainwin::Mainwin() 
  : entry{Gtk::manage(new Gtk::Entry{})} {

    // Define main window title and VBox
    set_title("Demo of Entry");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Entry.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-text-entry.html.en
    vbox->pack_start(*entry);
    entry->set_text("Entry's default text");
    entry->signal_activate().connect([this] {this->on_entry_activate();});

    vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_entry_activate() {
    Gtk::MessageDialog{*this, entry->get_text()}.run();
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "test.entry");
    Mainwin win;
    app->run(win);
}
