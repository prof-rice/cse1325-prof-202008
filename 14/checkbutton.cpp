#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_checkbutton_click();
  private:
    Gtk::CheckButton* checkbutton;
};

Mainwin::Mainwin() 
    : checkbutton{Gtk::manage(new Gtk::CheckButton{"Check Button)"})} {

    // Define main window title and VBox
    set_title("Demo of CheckButton");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1CheckButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-checkboxes.html.en
    vbox->pack_start(*checkbutton);
    checkbutton->set_active(true);
    checkbutton->signal_clicked().connect([this] {this->on_checkbutton_click();});

    vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_checkbutton_click() {
    Gtk::MessageDialog{*this, checkbutton->get_active() ? "Checked" : "Unchecked"}.run();
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "test.checkbutton");
    Mainwin win;
    app->run(win);
}
