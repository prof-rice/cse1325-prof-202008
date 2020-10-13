#include "imagedialog.h"

ImageDialog::ImageDialog(Gtk::Window& parent,
                         const std::string& file,
                         const Glib::ustring& message, 
                         bool use_markup, 
                         Gtk::MessageType type, 
                         Gtk::ButtonsType buttons, 
                         bool modal)
  : MessageDialog(parent, message, use_markup, type, buttons, modal), image{new Gtk::Image{file}} {
    get_content_area()->pack_start(*image);  // Add the Image to the MessageDialog
    image->show();                           // Make the Image visible
}

