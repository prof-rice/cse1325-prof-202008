#ifndef __IMAGEDIALOG_H
#define __IMAGEDIALOG_H

#include <gtkmm.h>

class ImageDialog : public Gtk::MessageDialog {
  public:
    // This constructor is (almost) identical to Gtk::MessageDialog
    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1MessageDialog.html
    ImageDialog(Gtk::Window& parent,
                const std::string& file, // This parameter is from Gtk::Image::Image
                const Glib::ustring& message="",  // Permit image-only dialog 
                bool use_markup=false, 
                Gtk::MessageType type=Gtk::MESSAGE_OTHER, 
                Gtk::ButtonsType buttons=Gtk::BUTTONS_OK, 
                bool modal=false);
  private:
    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Image.html
    Gtk::Image* image;
};
#endif
