#include "mainwin.h"
#include <fstream>

Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    set_title("CSE1325 Paint");

    // Notify when the main window is closing
    signal_delete_event().connect([this] (GdkEventAny* event) -> bool {this->on_delete_event(event);});

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   G A M E
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Painting", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_painting_click();});
    filemenu->append(*menuitem_new);

    //         S A V E   P A I N T I N G
    // Append Save As... to the File menu
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save _As", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);

    //         O P E N   P A I N T I N G
    // Append Open... to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

    //     N E W   P A I N T I N G
    // Add a new paint icon
    Gtk::ToolButton *new_painting_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_painting_button->set_tooltip_markup("Create a new painting, discarding any in progress");
    new_painting_button->signal_clicked().connect([this] {this->on_new_painting_click();});
    toolbar->append(*new_painting_button);

    //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit CSE1325 Paint");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);

    // C A N V A S
    // Provide a DrawingArea on which to paint
    canvas = Gtk::manage(new Graph_lib::Canvas{});
    canvas->set_hexpand(true);
    canvas->set_vexpand(true);
    vbox->pack_start(*canvas, Gtk::PACK_EXPAND_WIDGET, 0);
    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for messages
    msg = Gtk::manage(new Gtk::Label{"Welcome to CSE1325 Paint!"});
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_painting_click() {
    if (safe_to_exit()) canvas->clear();
}

// Signaled when the main window is about to close
// False enables closing the app, true aborts close
bool Mainwin::on_delete_event(GdkEventAny* event) {
    return !safe_to_exit();
}

bool Mainwin::safe_to_exit() {
  if (canvas->saved()) return true;
  Gtk::MessageDialog dialog{*this, "Unsaved data will be lost", false, 
                            Gtk::MESSAGE_WARNING, Gtk::BUTTONS_NONE};
  dialog.add_button("Save", 1);
  dialog.add_button("Discard", 2);
  dialog.add_button("Cancel", 3);
  int response = dialog.run();
  if (response == 1) {        // Save
    try {
        on_save_as_click();
        return true; // save was successful
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, "Unable to save data", false, Gtk::MESSAGE_ERROR}.run();
        return false;
    }
  } else if (response == 2) { // Discard
    canvas->clear();
    return true;
  } else {                    // Cancel
    return false;
  }
}

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog{};
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name(TITLE);
    auto logo = Gdk::Pixbuf::create_from_file("logo.png");
    dialog.set_logo(logo);
    dialog.set_version(VERSION);
    dialog.set_copyright("Copyright 2017-2019");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"George F. Rice"};
    dialog.set_authors(authors);
    //std::vector< Glib::ustring > artists = {};
    //dialog.set_artists(artists);
    //dialog.set_comments("The two players alternate taking 1 to 3 sticks from the pile.\nThe goal is to force your opponent to take the last stick.\nIf the computer button is up, it's a two player game.\nIf down, the computer is always Player 2.");
    dialog.run();
}

void Mainwin::on_save_as_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_ctp = Gtk::FileFilter::create();
    filter_ctp->set_name(EXT);
    filter_ctp->add_pattern("*."+EXT);
    dialog.add_filter(filter_ctp);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled."+EXT);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1) {
        std::ofstream ofs{dialog.get_filename()};
        //nim->save(ofs);
        if(!ofs) throw std::runtime_error{"Error writing file"};
    }
}
//
// The user wants to open a drawing from the filesystem
//
void Mainwin::on_open_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_ctp = Gtk::FileFilter::create();
    filter_ctp->set_name(EXT);
    filter_ctp->add_pattern("*."+EXT);
    dialog.add_filter(filter_ctp);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled."+EXT);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            // delete nim;
            std::ifstream ifs{dialog.get_filename()};
            // nim = new Nim{ifs};
            if(!ifs) throw std::runtime_error{"File contents bad"};
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open painting"}.run();
        }
    }
}


// /////////////////
// U T I L I T I E S
// /////////////////


