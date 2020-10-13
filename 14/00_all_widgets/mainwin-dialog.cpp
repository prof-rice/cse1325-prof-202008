#include "mainwin.h"
#include <cmath>

// Compare this dialog version with the main window version in mainwin.cpp

void Mainwin::dialog() {

    // Rather than class-level attributes, we dynamically create the widgets in our method
    Gtk::Button* button{Gtk::manage(new Gtk::Button{"Click this button!"})};
    Gtk::Entry* entry{Gtk::manage(new Gtk::Entry{})};
    Gtk::ComboBoxText* comboboxtext{Gtk::manage(new Gtk::ComboBoxText{true})};
    Gtk::ToggleButton* togglebutton{Gtk::manage(new Gtk::ToggleButton{"Toggle Button"})};
    Gtk::CheckButton* checkbutton{Gtk::manage(new Gtk::CheckButton{"Check Button (enables Scale)"})};
    Gtk::Frame* frame{Gtk::manage(new Gtk::Frame{"This Frame visually groups the RadioButtons"})};
    Gtk::RadioButton* radiobutton1{Gtk::manage(new Gtk::RadioButton{"Radio Button 1"})};
    Gtk::RadioButton* radiobutton2{Gtk::manage(new Gtk::RadioButton{"Radio Button 2"})};
    Gtk::SpinButton* spinbutton{Gtk::manage(new Gtk::SpinButton)};
    Gtk::Label* label{Gtk::manage(new Gtk::Label{"This Label is the square of SpinButton (above) or Scale (below)"})};
    Gtk::Scale* scale{Gtk::manage(new Gtk::Scale)};
    Gtk::ProgressBar* progressbar{Gtk::manage(new Gtk::ProgressBar)};

    // Next, we instance a Gtk::Dialog (which is derived from Gtk::Window)
    // Rather than creating a new Gtk::VBox, we set vbox to the dialog's content area
    Gtk::Dialog* dialog = new Gtk::Dialog{"As a Dialog", *this};
    auto vbox = dialog->get_content_area();

    // Rather than using methods to observe the widgets, the lambda's themselves provide the observer!
    // [this, &entry] means "make this available by value, and variable entry available by reference"
    // [&] means "make ALL local scope available by reference"
    // [=] means "make ALL local scope available by value"

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Button.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-pushbuttons.html.en
    vbox->pack_start(*button);
    button->set_tooltip_markup("Click me! I <i>double dog dare</i> you!"); 
    button->signal_clicked().connect([this] {Gtk::MessageDialog{*this, "Ouch in a dialog!"}.run();});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Entry.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-text-entry.html.en
    vbox->pack_start(*entry);
    entry->set_text("Entry's default text");
    entry->signal_activate().connect([this, &entry] {Gtk::MessageDialog{*this, entry->get_text()}.run();});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1ComboBox.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/combobox-example-simple.html.en
    vbox->pack_start(*comboboxtext);
    comboboxtext->append("ComboBoxText Row 1");
    comboboxtext->append("ComboBoxText Row 2");
    comboboxtext->append("ComboBoxText Row 3");
    comboboxtext->set_active(1);
    comboboxtext->signal_changed().connect([this, &comboboxtext] {
        std::string s = "Dialog Row " + std::to_string(comboboxtext->get_active_row_number())
                      + ": " + comboboxtext->get_active_text();
        Gtk::MessageDialog{*this, s}.run();
    });

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1ToggleButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-toggle-buttons.html.en
    vbox->pack_start(*togglebutton);
    togglebutton->signal_clicked().connect([this, &togglebutton] {
        Gtk::MessageDialog{*this, togglebutton->get_active() ? "Dialog Down" : "Dialog Up"}.run();
    });

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1CheckButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-checkboxes.html.en
    vbox->pack_start(*checkbutton);
    checkbutton->set_active(true);
    checkbutton->signal_clicked().connect([this, &scale, &checkbutton] {
        scale->set_sensitive(checkbutton->get_active()); // Checkbox controls scale's sensitivity
        Gtk::MessageDialog{*this, checkbutton->get_active() ? "Dialog Checked" : "Dialog Unchecked"}.run();
    });

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
    radiobutton1->signal_clicked().connect([this] {Gtk::MessageDialog{*this, "Dialog Radio Button 1"}.run();});
    radiobutton2->signal_clicked().connect([this] {Gtk::MessageDialog{*this, "Dialog Radio Button 2"}.run();});

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1SpinButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-spinbutton.html.en
    vbox->pack_start(*spinbutton);
    spinbutton->set_range(0.0, 1000.0);
    spinbutton->set_increments(1.0, 1.0);
    spinbutton->signal_value_changed().connect([this, &spinbutton, &label] {
        int sp = spinbutton->get_value();
        label->set_text(std::to_string(sp*sp));
    });

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Label.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-labels.html.en
    vbox->pack_start(*label);

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Scale.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-scale-widgets.html.en
    vbox->pack_start(*scale);
    scale->set_range(0.0, 100.0);
    scale->set_increments(1.0, 1.0);
    scale->signal_value_changed().connect([&] {
        int sp = scale->get_value();
        label->set_text(std::to_string(sp*sp));
        progressbar->set_fraction(sqrt(scale->get_value())/10.0);
    });

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1ProgressBar.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-progressbar.html.en
    vbox->pack_start(*progressbar);
    progressbar->set_show_text(true);
    progressbar->set_text("Dialog adjust ProgressBar (below) with Scale (above)");
    progressbar->set_fraction(0.0);

    vbox->show_all();

    // Now we simply run the dialog. When it closes, we delete it and exit the method.
    dialog->run();
    delete dialog;
}



