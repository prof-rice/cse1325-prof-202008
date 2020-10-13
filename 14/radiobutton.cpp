#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_radiobutton_click(int button);
  private:
    Gtk::Frame* frame; // Contains the 2 radio buttons
    Gtk::RadioButton* radiobutton1;
    Gtk::RadioButton* radiobutton2; // need 2 to demo groups
};

Mainwin::Mainwin() 
    : frame{Gtk::manage(new Gtk::Frame{"This Frame visually groups the RadioButtons"})},
      radiobutton1{Gtk::manage(new Gtk::RadioButton{"Radio Button 1"})},
      radiobutton2{Gtk::manage(new Gtk::RadioButton{"Radio Button 2"})} {

    // Define main window title and VBox
    set_title("Demo of RadioButton");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Frame.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-single-item-containers.html.en#sec-frame
    vbox->pack_start(*frame);  // Frames can include only one widget, so we need another VBox
    Gtk::VBox *vbox_frame = Gtk::manage(new Gtk::VBox);
    frame->add(*vbox_frame);

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1RadioButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-radio-buttons.html.en
    vbox_frame->pack_start(*radiobutton1); // Note: Added to the *frame* above
    vbox_frame->pack_start(*radiobutton2);
    radiobutton1->join_group(*radiobutton2); // Put radios in the same group (unlimited permitted)
    radiobutton1->signal_clicked().connect([this] {this->on_radiobutton_click(1);});
    radiobutton2->signal_clicked().connect([this] {this->on_radiobutton_click(2);});

    vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_radiobutton_click(int button) {
    Gtk::RadioButton* radiobutton = ((button == 1) ? radiobutton1 : radiobutton2);
    Gtk::MessageDialog{*this, "Radio Button " + std::to_string(button) +
                       (radiobutton->get_active() ? " active" : " inactive")}.run();
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "test.radiobutton");
    Mainwin win;
    app->run(win);
}
