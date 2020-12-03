#include <gtkmm.h>
#include <iostream>

class Coordinate {
  public:
    Coordinate(int x, int y) : _x{x}, _y{y} { }
    Coordinate() : Coordinate(0,0) { }
    friend std::ostream& operator<<(std::ostream& ost, const Coordinate& c) {
        ost << '(' << c._x << ',' << c._y << ')';
        return ost;
    }
    friend std::istream& operator>>(std::istream& ist, Coordinate& c) {
        ist >> c._x >> c._y;
        return ist;
    }
  private:
    int _x, _y;
};

template<class T>
class EntryDialog : public Gtk::MessageDialog {
  public:
    // This constructor is identical to Gtk::MessageDialog
    EntryDialog(Gtk::Window& parent, const Glib::ustring& message)
      : MessageDialog(parent, message), entry{Gtk::manage(new Gtk::Entry)} {
        get_content_area()->pack_start(*entry);  // Add the entry to the MessageDialog
        entry->show();                           // Make the Entry visible
    }

    // These methods are identical to those of the same name in Gtk::Entry
    void set_text (const Glib::ustring& text) {entry->set_text(text);}
    Glib::ustring get_text () const {return entry->get_text();}
    T get_data () const {
        std::istringstream iss{get_text()};
        T i;
        iss >> i;
        if(iss.fail()) throw std::runtime_error{"Unable to convert '" + get_text() + "' to " + typeid(i).name()};
        return i;
    }
  private:
    Gtk::Entry* entry;
};

int main (int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.entrydialog.template.v1_0");
    Gtk::Window win;
    {
      EntryDialog<double> dialog{win, "Enter a double"};
      dialog.run();
      double result = dialog.get_data();
      std::cout << result << std::endl;
    }
    {
      EntryDialog<Coordinate> dialog{win, "Enter a Coordinate as int int"};
      dialog.run();
      Coordinate result = dialog.get_data();
      std::cout << result << std::endl;
    }
}

