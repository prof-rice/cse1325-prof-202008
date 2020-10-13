#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_togglebutton_click();
  private:
    Gtk::ToggleButton* togglebutton;
};

Mainwin::Mainwin() 
    : togglebutton{Gtk::manage(new Gtk::ToggleButton{"Toggle Button"})} {

    // Define main window title and VBox
    set_title("Demo of ToggleButton");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1ToggleButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-toggle-buttons.html.en
    vbox->pack_start(*togglebutton);
    togglebutton->signal_clicked().connect([this] {this->on_togglebutton_click();});

    vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_togglebutton_click() {
    Gtk::MessageDialog{*this, togglebutton->get_active() ? "Down" : "Up"}.run();
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "test.togglebutton");
    Mainwin win;
    app->run(win);
}
