#include "mainwin.h"
#include "entrydialog.h"
#include <fstream>

const std::string APPNAME = "Manga Magic";
const std::string VERSION = "0.5";
const std::string DEFAULTFN = "untitled.manga";

Mainwin::Mainwin() : store{nullptr}, display{new Gtk::Label{}}, msg{new Gtk::Label{}}, filename{DEFAULTFN} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(640, 480);
    set_title("Manga Magic");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
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

    //         N E W   S T O R E
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Store", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new);

    //         S A V E   S T O R E
    // Append Save to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    //         S A V E   A S   S T O R E
    // Append Save As... to the File menu
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save _As", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);

    //         O P E N   S T O R E
    // Append Open... to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     I N S E R T
    // Create an Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //           C U S T O M E R
    // Append Customer to the Insert menu
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customer->signal_activate().connect([this] {this->on_new_customer_click();});
    insertmenu->append(*menuitem_customer);

    //           O R D E R
    // Append Order to the Insert menu
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_order->signal_activate().connect([this] {this->on_new_order_click();});
    insertmenu->append(*menuitem_order);

    //           T O O L
    // Append Tool to the Insert menu
    Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool", true));
    menuitem_tool->signal_activate().connect([this] {this->on_new_tool_click();});
    insertmenu->append(*menuitem_tool);

    //           P L A N T
    // Append Plant to the Insert menu
    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant", true));
    menuitem_plant->signal_activate().connect([this] {this->on_new_plant_click();});
    insertmenu->append(*menuitem_plant);
    
    //           M U L C H
    // Append Mulch to the Insert menu
    Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch", true));
    menuitem_mulch->signal_activate().connect([this] {this->on_new_mulch_click();});
    insertmenu->append(*menuitem_mulch);

    //     V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //           C U S T O M E R S
    // Append Customers to the View menu
    Gtk::MenuItem *menuitem_customers = Gtk::manage(new Gtk::MenuItem("_Customers", true));
    menuitem_customers->signal_activate().connect([this] {this->on_view_customers_click();});
    viewmenu->append(*menuitem_customers);

    //           O R D E R S
    // Append Orders to the View menu
    Gtk::MenuItem *menuitem_orders = Gtk::manage(new Gtk::MenuItem("_Orders", true));
    menuitem_orders->signal_activate().connect([this] {this->on_view_orders_click();});
    viewmenu->append(*menuitem_orders);

    //           P R O D U C T S
    // Append Products to the View menu
    Gtk::MenuItem *menuitem_products = Gtk::manage(new Gtk::MenuItem("_Products", true));
    menuitem_products->signal_activate().connect([this] {this->on_view_products_click();});
    viewmenu->append(*menuitem_products);


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

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

    //     N E W   S T O R E
    // Add a new store icon
    Gtk::ToolButton *new_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_store_button->set_tooltip_markup("Create a new store, discarding any in progress");
    new_store_button->signal_clicked().connect([this] {this->on_new_store_click();});
    toolbar->append(*new_store_button);

    //     O P E N   S T O R E
    // Add an open store icon
    Gtk::ToolButton *open_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    open_store_button->set_tooltip_markup("Open a store from disk file, discarding any in progress");
    open_store_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*open_store_button);

    //     S A V E   S T O R E
    // Add a save store icon
    Gtk::ToolButton *save_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    save_store_button->set_tooltip_markup("Save this store to disk file");
    save_store_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save_store_button);

    //     S A V E  A S  S T O R E
    // Add a save as store icon
    Gtk::ToolButton *save_as_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
    save_as_button->set_tooltip_markup("Save this store to new disk file");
    save_as_button->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*save_as_button);

    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep1);

    //     A D D   C U S T O M E R
    // Add a New Customer button to the toolbar
    Gtk::Image* customer_image = Gtk::manage(new Gtk::Image{"new_customer.png"});
    Gtk::ToolButton* new_cust_button = Gtk::manage(new Gtk::ToolButton(*customer_image));
    new_cust_button->set_tooltip_markup("Add a New Customer");
    new_cust_button->signal_clicked().connect([this] {this->on_new_customer_click();});
    toolbar->append(*new_cust_button);
    
    //     A D D   O R D E R
    // Add a New Order button to the toolbar
    Gtk::Image* order_image = Gtk::manage(new Gtk::Image{"new_order.png"});
    Gtk::ToolButton* new_order_button = Gtk::manage(new Gtk::ToolButton(*order_image));
    new_order_button->set_tooltip_markup("Add a New Order");
    new_order_button->signal_clicked().connect([this] {this->on_new_order_click();});
    toolbar->append(*new_order_button);

    Gtk::SeparatorToolItem *sep2 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep2);

    //     A D D   T O O L
    // Add a New Tool button to the toolbar
    Gtk::Image* tool_image = Gtk::manage(new Gtk::Image{"new_tool.png"});
    Gtk::ToolButton* new_tool_button = Gtk::manage(new Gtk::ToolButton(*tool_image));
    new_tool_button->set_tooltip_markup("Add a New Tool Product");
    new_tool_button->signal_clicked().connect([this] {this->on_new_tool_click();});
    toolbar->append(*new_tool_button);

    //     A D D   P L A N T
    // Add a New Plant button to the toolbar
    Gtk::Image* plant_image = Gtk::manage(new Gtk::Image{"new_plant.png"});
    Gtk::ToolButton* new_plant_button = Gtk::manage(new Gtk::ToolButton(*plant_image));
    new_plant_button->set_tooltip_markup("Add a New Plant Product");
    new_plant_button->signal_clicked().connect([this] {this->on_new_plant_click();});
    toolbar->append(*new_plant_button);
    
    //     A D D   M U L C H
    // Add a New Mulch button to the toolbar
    Gtk::Image* mulch_image = Gtk::manage(new Gtk::Image{"new_mulch.png"});
    Gtk::ToolButton* new_mulch_button = Gtk::manage(new Gtk::ToolButton(*mulch_image));
    new_mulch_button->set_tooltip_markup("Add a New Mulch Product");
    new_mulch_button->signal_clicked().connect([this] {this->on_new_mulch_click();});
    toolbar->append(*new_mulch_button);
    
    Gtk::SeparatorToolItem *sep3 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep3);


    //     V I E W   C U S T O M E R S
    // Add a View Customers button to the toolbar
    Gtk::Image* view_customers_image = Gtk::manage(new Gtk::Image{"view_customers.png"});
    Gtk::ToolButton* view_customers_button = Gtk::manage(new Gtk::ToolButton(*view_customers_image));
    view_customers_button->set_tooltip_markup("View All Customers");
    view_customers_button->signal_clicked().connect([this] {this->on_view_customers_click();});
    toolbar->append(*view_customers_button);
    
    //     V I E W   O R D E R S
    // Add a View Orders button to the toolbar
    Gtk::Image* view_orders_image = Gtk::manage(new Gtk::Image{"view_orders.png"});
    Gtk::ToolButton* view_orders_button = Gtk::manage(new Gtk::ToolButton(*view_orders_image));
    view_orders_button->set_tooltip_markup("View All Orders");
    view_orders_button->signal_clicked().connect([this] {this->on_view_orders_click();});
    toolbar->append(*view_orders_button);
    
    //     V I E W   P R O D U C T S
    // Add a View Products button to the toolbar
    Gtk::Image* view_products_image = Gtk::manage(new Gtk::Image{"view_products.png"});
    Gtk::ToolButton* view_products_button = Gtk::manage(new Gtk::ToolButton(*view_products_image));
    view_products_button->set_tooltip_markup("View All Products");
    view_products_button->signal_clicked().connect([this] {this->on_view_products_click();});
    toolbar->append(*view_products_button);
    
    
    // /////////////////////////// ////////////////////////////////////////////
    // M A I N   W I N D O W   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);
    
    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new store
    on_new_store_click(true);
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

// /////////////   FILE I/O   ////////////////

void Mainwin::on_new_store_click(bool untitled) {
    set_status();
    std::string name = "Untitled";
    try {
        if(!untitled) name = get_string("New store name?");
        filename = DEFAULTFN;
    } catch (std::exception& e) {
    }
    delete store; store = nullptr;
    store = new Store{name};
    if(!untitled) set_status("Created new store: " + name);
    set_title(APPNAME + " - " + store->name());
    on_view_products_click();
}

void Mainwin::on_save_click() {
    set_status();
    try {
        std::ofstream ofs{filename};
        store->save(ofs);
        if(!ofs) throw std::runtime_error{"Error writing file " + filename};
        set_status("Saved to " + filename);
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, "Unable to save store: " + std::string{e.what()},
            false, Gtk::MESSAGE_WARNING}.run();
    }
}

void Mainwin::on_save_as_click() {
    set_status();
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_manga = Gtk::FileFilter::create();
    filter_manga->set_name("MANGA files");
    filter_manga->add_pattern("*.manga");
    dialog.add_filter(filter_manga);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.manga");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1) {
        filename = dialog.get_filename();
        on_save_click();  // Delegate to save
    }
}
//
// The user wants to open a store from the filesystem
//
void Mainwin::on_open_click() {
    set_status();
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_manga = Gtk::FileFilter::create();
    filter_manga->set_name("MANGA files");
    filter_manga->add_pattern("*.manga");
    dialog.add_filter(filter_manga);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.manga");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            filename = dialog.get_filename();
            std::ifstream ifs{filename};
            delete store; store = nullptr;
            store = new Store{ifs};
            on_view_products_click();
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open store: " + std::string{e.what()},
                false, Gtk::MESSAGE_WARNING}.run();
            on_new_store_click(true);
        }
    }
    set_status("Opened " + filename);
    set_title(APPNAME + " - " + store->name());
    on_view_products_click();
}

// /////////////   NEW   ////////////////

void Mainwin::on_new_customer_click() {
    set_status();
    Gtk::Dialog dialog{"Insert Customer", *this};
    Gtk::Grid grid;
    dialog.get_content_area()->add(grid);

    Gtk::Label l_name{"Name"};
    grid.attach(l_name, 0, 0, 1, 1);
    Gtk::Label l_phone{"Phone"};
    grid.attach(l_phone, 0, 1, 1, 1);
    Gtk::Label l_email{"Email"};
    grid.attach(l_email, 0, 2, 1, 1);

    Gtk::Entry e_name;
    grid.attach(e_name, 1, 0, 1, 1);
    Gtk::Entry e_phone;
    e_phone.set_placeholder_text("xxx-xxx-xxxx");
    grid.attach(e_phone, 1, 1, 1, 1);
    Gtk::Entry e_email;
    e_email.set_placeholder_text("xxx@domain.com");
    grid.attach(e_email, 1, 2, 1, 1);

    dialog.add_button("Insert", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    std::string name;
    while(dialog.run()) {
        try {
            name = e_name.get_text();
            if(name.empty()) {e_name.set_text("### Required ###"); continue;}
            Customer customer{name, 
                              e_phone.get_text(),
                              e_email.get_text()};
            store->add_customer(customer);
            set_status("Added customer " + name);
            break;
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to create new customer " + name 
                                    + ": " + std::string{e.what()},
                false, Gtk::MESSAGE_WARNING}.run();
            break;
        }
    }
    on_view_customers_click();
}

void Mainwin::on_new_tool_click() {
    set_status();
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        store->add_product(*(new Tool{name, price, description}));
        set_status("Added tool " + name);
    } catch(std::exception& e) {
    }
    on_view_products_click();
}

void Mainwin::on_new_plant_click() {
    set_status();
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        std::string species = get_string("Species?");
        double d = get_double("Exposure? (1) Shade (2) Part Sun (3) Sun");
        Exposure exposure = (d==1.0) ? Exposure::SHADE : ((d==3.0) ? Exposure::SUN : Exposure::PARTSUN);
        store->add_product(*(new Plant{name, price, description, species, exposure}));
        set_status("Added plant " + name);
    } catch(std::exception& e) {
    }
    on_view_products_click();
}

void Mainwin::on_new_mulch_click() {
    set_status();
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        int volume = get_int("Volume (ft³)?");
        int i = get_int("Material? (1) Rubber (2) Pine (3) Cedar (4) Hardwood");
        Material material;
        if(i == 1)       material = Material::RUBBER;
        else if (i == 2) material = Material::PINE;
        else if (i == 3) material = Material::CEDAR;
        else             material = Material::HARDWOOD;
        store->add_product(*(new Mulch{name, price, description, volume, material}));
        set_status("Added mulch " + name);
    } catch(std::exception& e) {
    }
    on_view_products_click();
}


void Mainwin::on_new_order_click() {
    set_status();
    int ordernum;
    std::ostringstream oss;
    
    // Select a customer
    {
      Gtk::Dialog dialog{"Order for which customer?", *this};
    
      Gtk::ComboBoxText cbt;
      for(int i=0; i<store->customers(); ++i) {
        oss.str(""); // clear the string stream
        oss << store->customer(i);
        cbt.append(oss.str());
      }
      cbt.set_active(store->customers()-1);
      dialog.get_content_area()->add(cbt);
    
      dialog.add_button("Start Order", 1);
      dialog.add_button("Cancel", 0);
    
      dialog.show_all();
    
      if(dialog.run() == 0) return; 
      ordernum = store->add_order(store->customer(cbt.get_active_row_number()));
      set_status("Created order " + std::to_string(ordernum));
    }
    
    // Select products
    {
      Gtk::MessageDialog dialog{*this, "Add to Order " + std::to_string(ordernum)};
      
      // Quantity (spin button)
      Gtk::HBox qbox;
      Gtk::Label lq{"Quantity"};
      qbox.add(lq);
      Gtk::SpinButton sb;
      sb.set_range(1.0, 99.0);
      sb.set_increments(1.0, 10.0);
      qbox.add(sb);
      dialog.get_content_area()->add(qbox);
      
      // Product (combo box text)
      Gtk::ComboBoxText cbt;
      for(int i=0; i<store->products(); ++i) {
        oss.str("");
        oss << store->product(i);
        cbt.append(oss.str());
      }
      dialog.get_content_area()->add(cbt);

      // Buttons
      dialog.add_button("Add to Order", 1);    
      dialog.add_button("Order Complete", 0);
    
      // Collect products
      while(true) {
        // Show current order
        oss.str("");
        //oss << store->order(ordernum);
        Store::iterator order = store->begin() + ordernum;
        oss << **order; // Iterator deferences a pointer, so... double-dereference!
        dialog.set_secondary_text(oss.str());
        
        dialog.show_all();
    
        if(dialog.run() == 1)
          store->add_item(ordernum, store->product(cbt.get_active_row_number()), static_cast<int>(sb.get_value()));
        else
          break;
      }
    }
    
    // View the orders
    on_view_orders_click();
}

// /////////////   VIEW   ////////////////

void Mainwin::on_view_products_click() {
    std::ostringstream oss;
    oss << "<tt><u>Current Products</u>\n";
    for(int i=0; i<store->products(); ++i)
        oss << store->product(i) << '\n';
    oss << "</tt>";
    display->set_markup(oss.str());
}

void Mainwin::on_view_customers_click() {
    std::ostringstream oss;
    oss << "<tt><u>Current Customers</u>\n";
    for(int i=0; i<store->customers(); ++i)
        oss << store->customer(i) << '\n';
    oss << "</tt>";
    display->set_markup(oss.str());
}

void Mainwin::on_view_orders_click() {
    std::ostringstream oss;
    oss << "<tt><u>Current Orders</u>\n";
    int i=0;
    for(Order* order : *store) 
        oss << "ORDER " << i++ << '\n' << *order << "\n\n";
    //for(int i=0; i<store->orders(); ++i)        
    //    oss << "ORDER " << i << '\n' << store->order(i) << "\n\n";
    oss << "</tt>";
    display->set_markup(oss.str());
}

// /////////////   MISC   ////////////////

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("MANGA");
    auto logo = Gdk::Pixbuf::create_from_file("manga_logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Version " + VERSION);
    dialog.set_copyright("Copyright 2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"George F. Rice"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Manga Cats by naobim (Free for commercial use, No attribution required)\nhttps://pixabay.com/illustrations/reading-magazine-manga-comics-2654807/",
        "Tree by OpenClipart-Vectors (Free for commercial use, No attribution required)\nhttps://pixabay.com/vectors/ecological-leaf-leaves-nature-2026102/",
        "Customer icon by www.mindgraphy.com from the Noun Project, CC BY 3.0",
        "Fork Shovel icon by Syaiful Amri from the Noun Project, CC BY 3.0",
        "Plant icon by Matt Brooks from the Noun Project, CC BY 3.0",
        "Garden Wheelbarrow Cart icon by Vectors Point from the Noun Project, CC BY 3.0",
        "Shopping Cart icon by Simon Child from the Noun Project, CC BY 3.0",
        "Customers icon by JuliAya from the Noun Project, CC BY 3.0",
        "Sales Order icon by Sophia Bai from the Noun Project, CC BY 3.0",
        "Growing Plants icon by Adam Beasley from the Noun Project, CC BY 3.0",
        };
    dialog.set_artists(artists);
    dialog.run();
}

void Mainwin::on_quit_click() {
    close();
}

// /////////////   UTILITY   ////////////////

std::string Mainwin::get_string(std::string prompt) {
    EntryDialog edialog(*this, "<big>New Product</big>", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
    edialog.set_secondary_text(prompt, true);
    if(edialog.run() == Gtk::RESPONSE_CANCEL) throw std::runtime_error{"CANCEL"};
    return edialog.get_text();
}

double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}

int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}

void Mainwin::set_status(std::string status) {
    msg->set_markup(status);
}

