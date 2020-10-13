#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_label_click();
    void on_entry_activate();
    void on_button_click();
    void on_comboboxtext_activate();
    void on_togglebutton_click();
    void on_checkbutton_click();
    void on_radiobutton_click(int button);
    void on_spinbutton_value_changed();
    void on_scale_value_changed();
  private:
    // These are the widgets demonstrated in order
    Gtk::Entry* entry;
    Gtk::ComboBoxText* comboboxtext;
    Gtk::Button* button;
    Gtk::ToggleButton* togglebutton;
    Gtk::CheckButton* checkbutton;
    Gtk::Frame* frame; // Contains the 2 radio buttons
    Gtk::RadioButton* radiobutton1;
    Gtk::RadioButton* radiobutton2; // need 2 to demo groups
    Gtk::SpinButton* spinbutton;
    Gtk::Label* label;
    Gtk::Scale* scale;
    Gtk::ProgressBar* progressbar;

    Gtk::Button* dialog_button;
    void dialog();
};
