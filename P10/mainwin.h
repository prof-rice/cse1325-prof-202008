#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_store_click(bool untitled = false); // Create a new store
        void on_save_click();           // Save to existing filename
        void on_save_as_click();        // Save to a selected file
        void on_open_click();           // Open the selected file
        void on_new_customer_click();   // Create a new customer
        void on_new_tool_click();       // Create a new tool product
        void on_new_plant_click();      // Create a new plant product
        void on_new_mulch_click();      // Create a new mulch product
        void on_new_order_click();      // Create a new order
        void on_view_products_click();  // Update the display with products
        void on_view_customers_click(); // Update the display with customers
        void on_view_orders_click();    // Update the display with orders
        void on_about_click();          // Display the About dialog
        void on_quit_click();           // Exit the program
        
    private:
        int get_int(std::string prompt);
        double get_double(std::string prompt);
        std::string get_string(std::string prompt);
        void set_status(std::string status = "");
        
        Store* store;               // The currently active store
        Gtk::Label* display;        // Main display
        Gtk::Label* msg;            // Status message display
        std::string filename;       // Default filename
};
#endif 

