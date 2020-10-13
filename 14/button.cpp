#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_button_click();
  private:
    Gtk::Button* button;
};

Mainwin::Mainwin() 
  : button{Gtk::manage(new Gtk::Button{"Click this button!"})} {

    // Define main window title and VBox
    set_title("Demo of Button");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Button.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-pushbuttons.html.en
    vbox->pack_start(*button);
    button->set_tooltip_markup("Click me! I <i>dare</i> you!"); // works with ANY widget
    button->signal_clicked().connect([this] {this->on_button_click();});

    vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_button_click() {
    Gtk::MessageDialog{*this, "Ouch!"}.run();
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "test.button");
    Mainwin win;
    app->run(win);
}
