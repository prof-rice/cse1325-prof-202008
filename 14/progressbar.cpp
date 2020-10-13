#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_scale_value_changed();
  private:
    Gtk::Scale* scale;
    Gtk::ProgressBar* progressbar;
};

Mainwin::Mainwin() 
    : scale{Gtk::manage(new Gtk::Scale)},
      progressbar{Gtk::manage(new Gtk::ProgressBar)} {

    // Define main window title and VBox
    set_title("Demo of ProgressBar");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Scale.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-scale-widgets.html.en
    vbox->pack_start(*scale);
    scale->set_range(0.0, 100.0);
    scale->set_increments(1.0, 1.0);
    scale->signal_value_changed().connect([this] {this->on_scale_value_changed();});


    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1ProgressBar.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-progressbar.html.en
    vbox->pack_start(*progressbar);
    progressbar->set_show_text(true);
    progressbar->set_text("Adjust ProgressBar (below) with Scale (above)");
    progressbar->set_fraction(0.0);

    vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_scale_value_changed() {
    int sp = scale->get_value();
    progressbar->set_fraction(sqrt(scale->get_value())/10.0);
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "test.progressbar");
    Mainwin win;
    app->run(win);
}
