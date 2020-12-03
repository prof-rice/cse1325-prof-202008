#ifndef __ENTRYDIALOG_H
#define __ENTRYDIALOG_H

#include <gtkmm.h>

template<class T>
class EntryDialog : public Gtk::MessageDialog {
  public:
    // This constructor is identical to Gtk::MessageDialog
    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1MessageDialog.html
    EntryDialog(Gtk::Window& parent,
                const Glib::ustring& message, 
                bool use_markup=false, 
                Gtk::MessageType type=Gtk::MESSAGE_OTHER, 
                Gtk::ButtonsType buttons=Gtk::BUTTONS_OK, 
                bool modal=false)
      : MessageDialog(parent, message, use_markup, type, buttons, modal), entry{new Gtk::Entry{}} {
        get_content_area()->pack_start(*entry);  // Add the entry to the MessageDialog
        entry->show();                           // Make the Entry visible
    }

    // These methods are identical to those of the same name in Gtk::Entry
    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Entry.html
    void set_text (const Glib::ustring& text) {
        entry->set_text(text);
    }
    Glib::ustring get_text () const {
        return entry->get_text();
    }
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


#endif
