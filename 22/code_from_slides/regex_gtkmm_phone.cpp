#include <gtkmm.h>
#include <regex>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
  public:
    void on_click();
};

Mainwin::Mainwin() {
    set_default_size(100, 100);
    set_title("Regular Expressions Example");

    Gtk::Button* button = Gtk::manage(new Gtk::Button{"Click Me!"});
    button->signal_clicked().connect(
          sigc::mem_fun(*this, &Mainwin::on_click));
    add(*button);
    show_all();
} 
void Mainwin::on_click() {
    Gtk::Dialog* dialog = new Gtk::Dialog{"Enter a 7- or 10-digit phone number", *this};
          
    Gtk::Entry *entry = new Gtk::Entry{};
    entry->set_max_length(50);
    entry->show();
    dialog->get_vbox()->pack_start(*entry);

    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->set_default_response(1);

    std::regex phone_number{"(\\d{3,3}-)?\\d{3,3}-\\d{4,4}"};
    while (true) {
        if(!dialog->run()) break;
        std::string input = entry->get_text();

        if (std::regex_match(input, phone_number)) {
            Gtk::MessageDialog{*this, "Call " + input}.run();
            break;
        } else {
            entry->set_text("### Invalid ###");
        }
    }
    
    delete dialog;
}
int main (int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.regex.phone");
    Mainwin win;
    return app->run(win);
}

