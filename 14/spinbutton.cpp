#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_spinbutton_value_changed();
  private:
    Gtk::SpinButton* spinbutton;
    Gtk::Label* label;
};

Mainwin::Mainwin() 
    : spinbutton{Gtk::manage(new Gtk::SpinButton)},
      label{Gtk::manage(new Gtk::Label{"This Label is the square of SpinButton, whose range is 0 to 1000"})} {

    // Define main window title and VBox
    set_title("Demo of SpinButton");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1SpinButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-spinbutton.html.en
    vbox->pack_start(*spinbutton);
    spinbutton->set_range(0.0, 1000.0);
    spinbutton->set_increments(1.0, 25.0);
    spinbutton->signal_value_changed().connect([this] {this->on_spinbutton_value_changed();});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Label.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-labels.html.en
    vbox->pack_start(*label);

    vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_spinbutton_value_changed() {
    int sp = spinbutton->get_value();
    label->set_text(std::to_string(sp*sp));
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "test.spinbutton");
    Mainwin win;
    app->run(win);
}
