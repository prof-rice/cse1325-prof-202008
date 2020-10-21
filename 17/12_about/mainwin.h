#ifndef __MAINWIN_H
#define __MAINWIN_H

#include "canvas.h"
using Penmode = Graph_lib::Penmode;

const std::string TITLE = "CSE1325 Paint";
const std::string VERSION = "2.1.0";
const std::string EXT = "ctp";

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_painting_click();              // Create a new painting
        void on_save_click();                      // Save the painting to the file
        void on_save_as_click();                   // Save the painting to a different file
        void on_open_click();                      // Load the painting from a selected file
        void on_color_click();                     // Choose a color for lines
        void on_width_click();                     // Choose a width for lines
        void on_penmode_click(Penmode mode);       // Change the type of shape created
        void on_dash_pattern_click();              // Change the dash pattern
        void on_about_click();                     // Display About dialog
        void on_quit_click();                      // Exit the program
        bool all_data_saved();                     // True means safe to close or open other file
    // Signals
        bool on_delete_event(GdkEventAny* event);  // Called when main window is closing
    private:
        Graph_lib::Canvas* canvas;                 // The painting
        Gtk::RadioToolButton* button_segment;
        Gtk::RadioToolButton* button_contiguous;
        Gtk::Label* msg;                           // Status message display
};
#endif 

