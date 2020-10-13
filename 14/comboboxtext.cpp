#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_comboboxtext_changed();
  private:
    Gtk::ComboBoxText* comboboxtext;
};

Mainwin::Mainwin() 
    : comboboxtext{Gtk::manage(new Gtk::ComboBoxText{true})} {

    // Define main window title and VBox
    set_title("Demo of ComboBoxText");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1ComboBox.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/combobox-example-simple.html.en
    vbox->pack_start(*comboboxtext);
    comboboxtext->append("Coke");
    comboboxtext->append("Pepsi");
    comboboxtext->append("Dr. Pepper");
    comboboxtext->set_active(2);
    comboboxtext->signal_changed().connect([this] {this->on_comboboxtext_changed();});

    vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_comboboxtext_changed() {
    std::string s = "Row " + std::to_string(comboboxtext->get_active_row_number())
        + ": " + comboboxtext->get_active_text();
    Gtk::MessageDialog{*this, s}.run();
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "test.combotextbox");
    Mainwin win;
    app->run(win);
}
