#include "mainwin.h"

Mainwin::Mainwin() : button{new Gtk::Button{"Click for Example Dialog"}} {
  add(*button);
  button->signal_clicked().connect([this] {this->on_button_click();});
  button->show();
}

Mainwin::~Mainwin() { }

void Mainwin::on_button_click() {
    // Create the dialog on stack with title, avoiding the "discouraging warning"
    Gtk::Dialog dialog{"Specify Animal", *this};

    // Add the animal type
    Gtk::ComboBoxText c_type{true};
    c_type.append("Dog");
    c_type.append("Cat");
    c_type.append("Rabbit");
    c_type.set_active(0);

    // Add the drop down to the dialog's VBox
    dialog.get_content_area()->pack_start(c_type, Gtk::PACK_SHRINK, 0);

    // Accept the animal's name
    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;

    // Use an HBox to add a label to the left of the Entry
    Gtk::HBox hb_name;
    hb_name.pack_start(l_name);
    hb_name.pack_start(e_name);
    dialog.get_content_area()->pack_start(hb_name, Gtk::PACK_SHRINK, 0);

    // Select the animal's gender
    Gtk::Label l_gender{"Gender"};
    Gtk::ComboBoxText c_gender;
    c_gender.append("Female");
    c_gender.append("Male");
    c_gender.set_active(0);

    Gtk::HBox hb_gender;
    hb_gender.pack_start(l_gender);
    hb_gender.pack_start(c_gender);
    dialog.get_content_area()->pack_start(hb_gender, Gtk::PACK_SHRINK, 0);

    // Select the animal's age, usually a fairly small number (so accuracy of speed)
    Gtk::Label l_age{"Age"};
    Gtk::SpinButton s_age;
    s_age.set_range(0,99);
    s_age.set_increments(1,5);
    s_age.set_value(5);

    Gtk::HBox hb_age;
    hb_age.pack_start(l_age);
    hb_age.pack_start(s_age);
    dialog.get_content_area()->pack_start(hb_age, Gtk::PACK_SHRINK, 0);


    // Add 2 buttons (Gtk::Dialog handles buttons for you, just use add_button method!)
    // Button response IDs are from https://developer.gnome.org/gtkmm/stable/group__gtkmmEnums.html
    dialog.add_button("Select", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    // NOTE: The x in the title bar is Gtk::RESPONSE_DELETE_EVENT
    int response;

    // It's ready!  Now display it to the user.
    dialog.show_all();

    // Loop until the user does NOT click "OK". If we had other buttons (e.g., Apply or Update),
    //    response would tell us exactly which button the user clicked.
    // Note that because Gtk::Dialog is controlling the window, we don't have the option
    //   of responding to an Enter keystroke in a Gtk::Entry - we have to click "Select".
    //   If we create a custom Gtk::Window, however, we can register the Activate event
    //   for the Gtk::Entry widgets, and Enter becomes synonymous with clicking "Select".
    while((response = dialog.run()) == Gtk::RESPONSE_OK) {

        // Data validation: If the user doesn't enter a name for the animal, complain
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}

        // Otherwise, extract the information entered into the various widgets
        std::string animal_info = c_type.get_active_text() 
            + " named " + e_name.get_text() + " ("
            + (c_gender.get_active_row_number() ? "male" : "female")
            + " age " + std::to_string(s_age.get_value_as_int()) + ")";

         // Just display the information right back. In most applications, this is where you'd
         //   create a new object and add it to a std::vector or other container
         Gtk::MessageDialog{*this, "You selected a " + animal_info}.run();
    }
}
