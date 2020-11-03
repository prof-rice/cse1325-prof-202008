#ifndef __MAINWIN_H
#define __MAINWIN_H

#include "canvas.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_button_click(); 
        void on_edit_offset_activate();
        void on_quit_click();
    private:
        Canvas* canvas;
};
#endif 

