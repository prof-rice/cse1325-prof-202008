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

    // The grid allows placing widgets in the Dialog starting at (x,y) locations
    //    with upper left at (0,0), and specify a width and height for merged cells
    Gtk::Grid grid;

    // Add the animal type
    Gtk::Label t_name{"Type"};       // This labels the drop down
    Gtk::ComboBoxText c_type{true};  // Drop down with an Entry (true)
    c_type.append("Dog");            // Add the predefined options
    c_type.append("Cat");
    c_type.append("Rabbit");
    c_type.set_active(0);

    grid.attach(t_name, 0, 0, 1, 1); // Attach at (0,0) with single width and height
    grid.attach(c_type, 1, 0, 2, 1); // Attach at (1,0) with double width, single height

    // Accept the animal's name
    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;               // Accept any line of text

    grid.attach(l_name, 0, 1, 1, 1);
    grid.attach(e_name, 1, 1, 2, 1);

    // Select the animal's gender
    Gtk::Label l_gender{"Gender"};
    Gtk::ComboBoxText c_gender;      // A drop-down with NO Entry (false is default)
    c_gender.append("Female");       // Row 0
    c_gender.append("Male");         // Row 1
    c_gender.set_active(0);          // Specify the pre-selected default

    grid.attach(l_gender, 0, 2, 1, 1);
    grid.attach(c_gender, 1, 2, 2, 1);

    // Select the animal's age, usually a fairly small number (so accuracy of speed)
    Gtk::HBox hb_age;
    Gtk::Label l_age{"Age"};
    Gtk::SpinButton s_age;
    s_age.set_range(0,99);
    s_age.set_increments(1,5);       // Single clicks change by 1, hold down quickly by 5
    s_age.set_value(5);              // Specify the pre-selected default

    grid.attach(l_age, 0, 3, 1, 1);
    grid.attach(s_age, 1, 3, 2, 1);

    // Now add the grid to the dialog's VBox (called its "content area")
    dialog.get_content_area()->add(grid);

    // Add 2 buttons (Gtk::Dialog handles buttons for you, just use add_button method!)
    // Button response IDs are from https://developer.gnome.org/gtkmm/stable/group__gtkmmEnums.html
    dialog.add_button("Select", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    // NOTE: The x in the title bar to close the dialog is Gtk::RESPONSE_DELETE_EVENT
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
