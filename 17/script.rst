00_baseline
===========

This is the previous class' Graph_lib library.

01_refactor
===========

We replace main.cpp with Nim, add the Mainwin class, then edit to save as much as will be useful:

* File > New / Quit, Edit > Open / Save As, and Help > About
* Replace the Gtk::Label data area with a Gtk::DrawingArea

02_dirty_bit
============

Must detect main window closing to handle unsaved data

* Canvas - add dirty bit and saved() method
* Mainwin - **override** on_delete_event with dialog

03_discrete_lines
=================

Must detect click inside DrawingArea with **override** on_button_press_event

* Canvas - on_button_press_event override

04_rubber_band
==============

Need a *temporary* shape that changes whenever the mouse moves
Need to detect mouse movement

* Canvas - Shape* rubber_band and on_motion_notify_event

05_change_color
===============

* Shape - need to store a color and use it in draw()
* Line - need a color to delegate to Shape constructor
* Canvas - need default color with setter / getter
* Mainwin - add menu / toolbar button and on_color_click

06_pen_width
============

* Shape - need to store a width and use it in draw()
* Line - need a width to delegate to Shape constructor
* Canvas - need default width with setter / getter
* Mainwin - add menu / toolbar button and on_width_click


.. raw:: pdf

    PageBreak


07_file_io
==========

* Point - void save and constructor for I/O
* Shape - virtual void save and constructor for I/O
* Line - constructor to delegate to Shape's input constructor
* Canvas - save and load methods (not constructor - added to Gtk::Window)
* Mainwin - add Save menu / buttons, on_save_click, lots of reorg

08_contiguous_mode
==================

* Point - fix bug in equality operators
* Polyline - handle color and width, just like line
* Canvas - add Penmode enum class, penmode with setter/getter + previous penmode, add_point (to last shape), click_in_progress becomes int, extend on_button_press_event
* Mainwin - Add RadioToolButtons and on_penmode_click

09_freehand_mode
================

* Polyline - fix bug: missing istream constructor
* Canvas - extend Penmode type, fix bug: mangled Polyline name, add freehand code to on_motion_notify_event
* Mainwin - Add Freehand menu item and RadioToolButton

10_dashes
=========

* Shape - Add dash pattern constants, set_dash in draw(), extend file format and I/O code (FILE COMPATIBILITY)
* Line and Polyline - Add dash int to delegate to Shape
* Canvas - Add dash
* Mainwin - Add on_dash_pattern_click with custom dialog (no standard *sob*)

11_undo
=======

* Shape - Add undo()
* Mainwin - Add Edit > Undo -- How would we implement redo()?

12_about
========
* Mainwin - Fix version number and artist credits prior to first release







