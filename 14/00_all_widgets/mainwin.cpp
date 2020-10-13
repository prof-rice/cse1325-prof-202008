#include "mainwin.h"
#include <cmath>

// Compare this main window version with the dialog version in mainwin-dialog.cpp

Mainwin::Mainwin() 

    // This is the Mainwin's initialization list, which
    //   specifies construction of all of the widgets
  : button{Gtk::manage(new Gtk::Button{"Click this button!"})},
    entry{Gtk::manage(new Gtk::Entry{})},
    comboboxtext{Gtk::manage(new Gtk::ComboBoxText{true})},
    togglebutton{Gtk::manage(new Gtk::ToggleButton{"Toggle Button"})},
    checkbutton{Gtk::manage(new Gtk::CheckButton{"Check Button (enables Scale)"})},
    frame{Gtk::manage(new Gtk::Frame{"This Frame visually groups the RadioButtons"})},
    radiobutton1{Gtk::manage(new Gtk::RadioButton{"Radio Button 1"})},
    radiobutton2{Gtk::manage(new Gtk::RadioButton{"Radio Button 2"})},
    spinbutton{Gtk::manage(new Gtk::SpinButton)},
    label{Gtk::manage(new Gtk::Label{"This Label is the square of SpinButton (above) or Scale (below)"})},
    scale{Gtk::manage(new Gtk::Scale)},
    progressbar{Gtk::manage(new Gtk::ProgressBar)},
    dialog_button{Gtk::manage(new Gtk::Button{"As a dialog..."})}

    // This is the constructor body, which configures and packs each widget
    //     into a VBox that has been added to the main window
{
    set_title("Demo of Common gtkmm Widgets");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Button.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-pushbuttons.html.en
    vbox->pack_start(*button);
    button->set_tooltip_markup("Click me! I <i>dare</i> you!"); // works with ANY widget
    button->signal_clicked().connect([this] {this->on_button_click();});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Entry.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-text-entry.html.en
    vbox->pack_start(*entry);
    entry->set_text("Entry's default text");
    entry->signal_activate().connect([this] {this->on_entry_activate();});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1ComboBox.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/combobox-example-simple.html.en
    vbox->pack_start(*comboboxtext);
    comboboxtext->append("ComboBoxText Row 1");
    comboboxtext->append("ComboBoxText Row 2");
    comboboxtext->append("ComboBoxText Row 3");
    comboboxtext->set_active(1);
    comboboxtext->signal_changed().connect([this] {this->on_comboboxtext_activate();});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1ToggleButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-toggle-buttons.html.en
    vbox->pack_start(*togglebutton);
    togglebutton->signal_clicked().connect([this] {this->on_togglebutton_click();});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1CheckButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-checkboxes.html.en
    vbox->pack_start(*checkbutton);
    checkbutton->set_active(true);
    checkbutton->signal_clicked().connect([this] {this->on_checkbutton_click();});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Frame.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-single-item-containers.html.en#sec-frame
    vbox->pack_start(*frame);  // Frames can include only one widget, so we need another VBox
    Gtk::VBox *vbox_frame = Gtk::manage(new Gtk::VBox);
    frame->add(*vbox_frame);

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1RadioButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-radio-buttons.html.en
    vbox_frame->pack_start(*radiobutton1); // Note: Added to the *frame* above
    vbox_frame->pack_start(*radiobutton2);
    radiobutton1->join_group(*radiobutton2); // Put radios in the same group (unlimited permitted)
    radiobutton1->signal_clicked().connect([this] {this->on_radiobutton_click(1);});
    radiobutton2->signal_clicked().connect([this] {this->on_radiobutton_click(2);});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1SpinButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-spinbutton.html.en
    vbox->pack_start(*spinbutton);
    spinbutton->set_range(0.0, 1000.0);
    spinbutton->set_increments(1.0, 1.0);
    spinbutton->signal_value_changed().connect([this] {this->on_spinbutton_value_changed();});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Label.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-labels.html.en
    vbox->pack_start(*label);

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Scale.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-scale-widgets.html.en
    vbox->pack_start(*scale);
    scale->set_range(0.0, 100.0);
    scale->set_increments(1.0, 1.0);
    scale->signal_value_changed().connect([this] {this->on_scale_value_changed();});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1ProgressBar.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-progressbar.html.en
    vbox->pack_start(*progressbar);
    progressbar->set_show_text(true);
    progressbar->set_text("Adjust ProgressBar (below) with Scale (above)");
    progressbar->set_fraction(0.0);

    // ---------------------------------------------
    // Or, as a dialog box...
    vbox->pack_start(*dialog_button);
    dialog_button->set_tooltip_markup("See this window as a dialog box");
    dialog_button->signal_clicked().connect([this] {this->dialog();});

    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////
// Callbacks
// /////////

void Mainwin::on_button_click() {
    Gtk::MessageDialog{*this, "Ouch!"}.run();
}

void Mainwin::on_entry_activate() {
    Gtk::MessageDialog{*this, entry->get_text()}.run();
}

void Mainwin::on_comboboxtext_activate() {
    std::string s = "Row " + std::to_string(comboboxtext->get_active_row_number())
        + ": " + comboboxtext->get_active_text();
    Gtk::MessageDialog{*this, s}.run();
}

void Mainwin::on_togglebutton_click() {
    Gtk::MessageDialog{*this, togglebutton->get_active() ? "Down" : "Up"}.run();
}

void Mainwin::on_checkbutton_click() {
    scale->set_sensitive(checkbutton->get_active()); // Checkbox controls scale's sensitivity
    Gtk::MessageDialog{*this, checkbutton->get_active() ? "Checked" : "Unchecked"}.run();
}

void Mainwin::on_radiobutton_click(int button) {
    Gtk::MessageDialog{*this, "Radio Button " + std::to_string(button)}.run();
}
void Mainwin::on_spinbutton_value_changed() {
    int sp = spinbutton->get_value();
    label->set_text(std::to_string(sp*sp));
}
void Mainwin::on_scale_value_changed() {
    int sp = scale->get_value();
    label->set_text(std::to_string(sp*sp));
    progressbar->set_fraction(sqrt(scale->get_value())/10.0);
}


