#include "mainwin.h"
#include <fstream>

Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 400);
    set_title("CSE1325 Paint");

    // Notify when the main window is closing
    signal_delete_event().connect([this] (GdkEventAny* event) -> bool {this->on_delete_event(event);});

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // ==================================================
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
    // Append Save to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem{"_Save", true});
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    //         S A V E   P A I N T I N G   A S
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

    //     E D I T
    // Create an Edit menu and add to the menu bar
     Gtk::MenuItem *menuitem_edit = Gtk::manage(new Gtk::MenuItem{"_Edit", true});
    menubar->append(*menuitem_edit);
    Gtk::Menu *editmenu = Gtk::manage(new Gtk::Menu{});
    menuitem_edit->set_submenu(*editmenu);

    //         U N D O
    // Append Undo to the Edit menu
    Gtk::MenuItem *menuitem_undo = Gtk::manage(new Gtk::MenuItem{"_Undo", true});
    menuitem_undo->signal_activate().connect([this] {this->canvas->undo();});
    editmenu->append(*menuitem_undo);

    //     P E N
    // Create a Pen menu and add to the menu bar
    Gtk::MenuItem *menuitem_pen = Gtk::manage(new Gtk::MenuItem{"_Pen", true});
    menubar->append(*menuitem_pen);
    Gtk::Menu *penmenu = Gtk::manage(new Gtk::Menu{});
    menuitem_pen->set_submenu(*penmenu);

    //         C O L O R
    // Append Color to the Pen menu
    Gtk::MenuItem *menuitem_color = Gtk::manage(new Gtk::MenuItem{"_Color", true});
    menuitem_color->signal_activate().connect([this] {this->on_color_click();});
    penmenu->append(*menuitem_color);

    //         W I D T H
    // Append Width to the Pen menu
    Gtk::MenuItem *menuitem_width = Gtk::manage(new Gtk::MenuItem{"_Width", true});
    menuitem_width->signal_activate().connect([this] {this->on_width_click();});
    penmenu->append(*menuitem_width);

    //         D A S H   P A T T E R N S
    // Append dash patterns to the Pen menu
    Gtk::MenuItem *menuitem_dash_pattern = Gtk::manage(new Gtk::MenuItem{"_Dash Pattern", true});
    menuitem_dash_pattern->signal_activate().connect([this] {this->on_dash_pattern_click();});
    penmenu->append(*menuitem_dash_pattern);

    //         P E N   M O D E : S E G M E N T
    // Append Segment to the Pen menu
    Gtk::MenuItem *menuitem_pen_mode_segment = Gtk::manage(new Gtk::MenuItem{"Line _Segments", true});
    menuitem_pen_mode_segment->signal_activate().connect([this] {this->on_penmode_click(Penmode::SEGMENT);});
    penmenu->append(*menuitem_pen_mode_segment);

    //         P E N   M O D E : C O N T I G U O U S
    // Append Contiguous to the Pen menu
    Gtk::MenuItem *menuitem_pen_mode_contiguous = Gtk::manage(new Gtk::MenuItem{"_Contiguous Lines", true});
    menuitem_pen_mode_contiguous->signal_activate().connect([this] {this->on_penmode_click(Penmode::CONTIGUOUS);});
    penmenu->append(*menuitem_pen_mode_contiguous);

    //         P E N   M O D E : F R E E H A N D
    // Append Freehand to the Pen menu
    Gtk::MenuItem *menuitem_pen_mode_freehand = Gtk::manage(new Gtk::MenuItem{"_Freehand", true});
    menuitem_pen_mode_freehand->signal_activate().connect([this] {this->on_penmode_click(Penmode::FREEHAND);});
    penmenu->append(*menuitem_pen_mode_freehand);

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

    // ================================================
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

    //     S A V E   D R A W I N G
    // Save a drawing to the default filename
    Gtk::ToolButton *save_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    save_button->set_tooltip_markup("Save drawing to the default filename");
    save_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save_button);

    //     O P E N   D R A W I N G
    // Open a drawing from disk
    Gtk::ToolButton *open_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    open_button->set_tooltip_markup("Open a drawing");
    open_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*open_button);

    // ------------------------
    //     P E N   C O L O R
    // Add a new pen color icon
    Gtk::Image *button_pen_color_image = 
        Gtk::manage(new Gtk::Image("select_pen_color.png"));
    Gtk::ToolButton *button_pen_color = 
        Gtk::manage(new Gtk::ToolButton(*button_pen_color_image));
    button_pen_color->set_tooltip_markup("Select pen color");
    button_pen_color->signal_clicked().connect([this] {this->on_color_click();});
    Gtk::SeparatorToolItem *sep_color = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep_color);
    toolbar->append(*button_pen_color);

    //     P E N   W I D T H
    // Add a set pen width icon
    Gtk::Image *button_pen_width_image = 
        Gtk::manage(new Gtk::Image("select_pen_width.png"));
    Gtk::ToolButton *button_pen_width = 
        Gtk::manage(new Gtk::ToolButton(*button_pen_width_image));
    button_pen_width->set_tooltip_markup("Select pen width");
    button_pen_width->signal_clicked().connect([this] {this->on_width_click();});
    toolbar->append(*button_pen_width);

    //     P E N   M O D E : S E G M E N T
    // Add a toggle button to enable segment pen mode
    Gtk::Image *segment_image = Gtk::manage(new Gtk::Image("segment.png"));
    button_segment = Gtk::manage(new Gtk::RadioToolButton(*segment_image));
    button_segment->set_tooltip_markup("Draw line segments");
    auto group = button_segment->get_group();
    button_segment->signal_clicked().connect([this] {this->on_penmode_click(Penmode::SEGMENT);});
    toolbar->append(*button_segment);

    //     P E N   M O D E : C O N T I G U O U S
    // Add a toggle button to enable contiguous pen mode
    Gtk::Image *contiguous_image = Gtk::manage(new Gtk::Image("contiguous.png"));
    button_contiguous = Gtk::manage(new Gtk::RadioToolButton(*contiguous_image));
    button_contiguous->set_tooltip_markup("Draw contiguous lines");
    button_contiguous->set_group(group);
    button_contiguous->signal_clicked().connect([this] {this->on_penmode_click(Penmode::CONTIGUOUS);});
    toolbar->append(*button_contiguous);

    //     P E N   M O D E : F R E E H A N D
    // Add a toggle button to enable freehand pen mode
    Gtk::Image *freehand_image = Gtk::manage(new Gtk::Image("freehand.png"));
    Gtk::RadioToolButton *button_freehand = Gtk::manage(new Gtk::RadioToolButton(*freehand_image));
    button_freehand->set_tooltip_markup("Draw freehand");
    button_freehand->set_group(group);
    button_freehand->signal_clicked().connect([this] {this->on_penmode_click(Penmode::FREEHAND);});
    toolbar->append(*button_freehand);

    // ------------------------
    //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit CSE1325 Paint");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);

    // =======================================
    // C A N V A S
    // Provide a DrawingArea on which to paint
    canvas = Gtk::manage(new Graph_lib::Canvas{});
    canvas->set_hexpand(true);
    canvas->set_vexpand(true);
    vbox->pack_start(*canvas, Gtk::PACK_EXPAND_WIDGET, 0);

    // =======================================
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
    if (all_data_saved()) canvas->clear();
}

void Mainwin::on_save_click() {
    try {
        std::ofstream ofs{canvas->get_filename()};
        ofs << TITLE << '\n' << VERSION << '\n';
        canvas->save(ofs);
    } catch(std::exception e) {
        Gtk::MessageDialog{*this, "Unable to save data", false, Gtk::MESSAGE_ERROR}.run();
    }
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
        canvas->set_filename(dialog.get_filename());
        on_save_click();
    }
}
//
// The user wants to open a drawing from the filesystem
//
void Mainwin::on_open_click() {
    // Don't lose existing data
    if(!all_data_saved()) return;

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
            std::ifstream ifs{dialog.get_filename()};
            std::string title, version;
            std::getline(ifs, title);
            std::getline(ifs, version);
            if(title != TITLE || version != VERSION)
                throw std::runtime_error{"Not an " + EXT + " file"};
            canvas->load(ifs);
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open painting", false, Gtk::MESSAGE_ERROR}.run();
        }
    }
}

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_color_click() {
  Gtk::ColorChooserDialog dialog("Please choose a color");
  dialog.set_transient_for(*this);  // Avoid the “discouraging” warning

  dialog.set_rgba(canvas->get_pen_color());  // Set the current color as default

  int result = dialog.run();

  if (result == Gtk::RESPONSE_OK)
      canvas->set_pen_color(dialog.get_rgba());
}

void Mainwin::on_width_click() {
    // Create a custom dialog for setting line width
    Gtk::Dialog dialog{"Select Pen Width", *this};

    // The lower widget is a slider (Gtk "scale"), so the user can mouse the new width
    Gtk::Scale scale{};
    scale.set_range(1.0,10.0);
    scale.set_value(canvas->get_pen_width());  // Preset scale to current width
    scale.show();
    dialog.get_vbox()->pack_start(scale);

    // OK and Cancel buttons
    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.set_default_response(1);

    // Show the dialog, get the button pressed
    dialog.show_all();
    int result = dialog.run();
    if (result == 1) canvas->set_pen_width(scale.get_value());
    dialog.close();
}

void Mainwin::on_penmode_click(Penmode mode) {
    canvas->set_penmode(mode);
}

void Mainwin::on_dash_pattern_click() {
    Gtk::Dialog dialog{"Select Dash Pattern", *this};
    Gtk::ComboBoxText c_dash;
    c_dash.set_size_request(160);
    c_dash.append("Solid Line");
    c_dash.append("Alternating");
    c_dash.append("Mostly Dash");
    c_dash.append("Dash Dot");
    dialog.get_vbox()->pack_start(c_dash, Gtk::PACK_SHRINK);

    // Show dialog
    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.show_all();

    if (dialog.run()) canvas->set_pen_dash(c_dash.get_active_row_number());
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

// /////////////
// S I G N A L S
// /////////////

// Signaled when the main window is about to close
// False enables closing the app, true aborts close
bool Mainwin::on_delete_event(GdkEventAny* event) {
    return !all_data_saved();
}

// /////////////////
// U T I L I T I E S
// /////////////////

// Returns true if all data is safe, and thus we can start a new drawing
// or open an existing drawing
bool Mainwin::all_data_saved() {
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



