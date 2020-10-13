#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_scale_value_changed();
  private:
    Gtk::Scale* scale;
    Gtk::Label* label;
};

Mainwin::Mainwin() 
    : scale{Gtk::manage(new Gtk::Scale)},
      label{Gtk::manage(new Gtk::Label{"This Label is the square of Scale, whose range is 0 to 100"})} {

    // Define main window title and VBox
    set_title("Demo of Scale");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Scale.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-scale-widgets.html.en
    vbox->pack_start(*scale);
    scale->set_range(0.0, 100.0);
    scale->set_increments(1.0, 1.0);
    scale->signal_value_changed().connect([this] {this->on_scale_value_changed();});


    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Label.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-labels.html.en
    vbox->pack_start(*label);

    vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_scale_value_changed() {
    int sp = scale->get_value();
    label->set_text(std::to_string(sp*sp));
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "test.scale");
    Mainwin win;
    app->run(win);
}
