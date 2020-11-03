#include "mainwin.h"
#include <iostream> // for std::cerr logging
#include <fstream>

Mainwin::Mainwin()  {
    canvas = Gtk::manage(new Canvas{});

    set_default_size(400, 400);
    // Title may vary  ;-)
    set_title("Electric Marker");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //     I M A g E
    // Create an Image menu and add to the menu bar
    Gtk::MenuItem *menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Image", true));
    menubar->append(*menuitem_edit);
    Gtk::Menu *editmenu = Gtk::manage(new Gtk::Menu());
    menuitem_edit->set_submenu(*editmenu);

    //         O F F S E T 
    // Append Offset to the File menu
    Gtk::MenuItem *menuitem_offset = Gtk::manage(new Gtk::MenuItem("_Offset", true));
    menuitem_offset->signal_activate().connect([this] {this->on_edit_offset_activate();});
    editmenu->append(*menuitem_offset);
    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);

    //      B U T T O N
    // Add an icon for a button
    //Gtk::Image* button1_image = Gtk::manage(new Gtk::Image{"toolbutton.png"});
    //Gtk::ToolButton* button1 = Gtk::manage(new Gtk::ToolButton(*button1_image));
    Gtk::ToolButton* button1 = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    button1->set_tooltip_markup("Select a file to draw");
    button1->signal_clicked().connect([this] {this->on_button_click();});
    toolbar->append(*button1);

    // /////////////////////////// ////////////////////////////////////////////
    // D I S P L A Y
    // Provide a text entry box 
    canvas = Gtk::manage(new Canvas{});
    canvas->set_hexpand(true);
    canvas->set_vexpand(true);
    vbox->add(*canvas);
    
    // Make the box and everything in it visible
    vbox->show_all();

}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////


void Mainwin::on_button_click(){
    // Select a file
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_txt = Gtk::FileFilter::create();
    filter_txt->set_name("TXT files");
    filter_txt->add_pattern("*.txt");
    dialog.add_filter(filter_txt);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.txt");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_ACCEPT);

    int result = dialog.run();

    if (result != Gtk::RESPONSE_ACCEPT) return;
    std::string filename = dialog.get_filename();

    // Clear the drawing
    canvas->clear();

    // Read points from file
    int num_points;
    double x, y;
    std::ifstream ifs{filename};
    ifs >> num_points;
    while(ifs && num_points--) {
        ifs >> x >> y;
        canvas->add(x, y);
    }
    if(ifs.fail()) throw std::runtime_error{filename + " failed"};   
    if(ifs.bad())  throw std::runtime_error{"bad " + filename};
    
    // Draw the points
    canvas->queue_draw(); 
}


void Mainwin::on_edit_offset_activate()  {
    // Create the dialog on stack with title, avoiding the "discouraging warning"
    Gtk::Dialog dialog{"Specify Offset", *this};

    // Accept the animal's name
    Gtk::Label l_x{"X"};
    Gtk::Entry e_x;

    // Use an HBox to add a label to the left of the Entry
    Gtk::HBox hb_x;
    hb_x.pack_start(l_x);
    hb_x.pack_start(e_x);
    dialog.get_content_area()->pack_start(hb_x, Gtk::PACK_SHRINK, 0);

    // Accept the animal's name
    Gtk::Label l_y{"Y"};
    Gtk::Entry e_y;

    // Use an HBox to add a label to the left of the Entry
    Gtk::HBox hb_y;
    hb_y.pack_start(l_y);
    hb_y.pack_start(e_y);
    dialog.get_content_area()->pack_start(hb_y, Gtk::PACK_SHRINK, 0);

    // Add 2 buttons (Gtk::Dialog handles buttons for you, just use add_button method!)
    // Button response IDs are from https://developer.gnome.org/gtkmm/stable/group__gtkmmEnums.html
    dialog.add_button("Set Offset", Gtk::RESPONSE_OK);
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
    if(dialog.run() == Gtk::RESPONSE_OK) {
        try {
            canvas->offset(std::stod(e_x.get_text()), std::stod(e_x.get_text()));
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "Invalid offset"}.run();
        }
    }
}
void Mainwin::on_quit_click() {close();}

