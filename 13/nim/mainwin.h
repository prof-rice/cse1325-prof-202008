#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "nim.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_game_click();          // Create a new game
        //void on_button1_click();         // Select one stick from pile
        //void on_button2_click();         // Select two sticks from pile
        //void on_button3_click();         // Select three sticks from pile
        void on_button_click(int button);  // NEW - Select 1, 2, or 3 sticksf from pile
        void on_computer_player_click();   // Enable / disable computer player
        void on_rules_click();             // Show the rules
        void on_about_click();             // Display About dialog
        void on_quit_click();              // Exit the game
    private:
        void set_sticks();                       // Update display, robot move
        Nim *nim;                                // Current game board

        Gtk::Label *sticks;                      // Display of sticks on game board
        Gtk::Label *msg;                         // Status message display
        Gtk::ToolButton *button1;                // Button to select 1 stick
        Gtk::ToolButton *button2;                // Button to select 2 sticks
        Gtk::ToolButton *button3;                // Button to select 3 sticks
        Gtk::ToggleToolButton *computer_player;  // Button to enable robot
};
#endif 

