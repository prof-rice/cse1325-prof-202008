Test gtkmm
==========

To build the code in main.cpp, use the Makefile in lxterminal:

  ``make``

The Makefile creates an executable named simpley "hello", whcih may be executed in lxterminal using

  ``./hello``

The leading "./" just means "in the current directory". Unlike Windows, Linux will NOT run programs in the current directory without the "./". This is a security feature.

---

If you want to delete all of the build products and start over, first "clean" the directory, then run make again. Use these two commands:

  ``make clean``
  ``make``

Since commands can be separated on a single line using ;, you can also do this:

  ``make clean ; make``

---

If the above programs complain of missing libraries, you'll need to install gtkmm. You may use the following commands, or type

``./install_gtkmm``

in this directory to run them all under Ubuntu and similar Linux operating systems (it will ask for your password, and you may have to hit Enter a few times to acknowledge installation of these applications).

    $ #Do NOT type the $ - that's a prompt!
    $ sudo apt update
    $ sudo apt install build-essential
    $ sudo apt install ddd
    $ sudo apt install libgtkmm-3.0-dev
    $ sudo apt install libgstreamermm-1.0-dev
    $ sudo apt install libgtkmm-3.0-doc
    $ sudo apt install libgstreamermm-1.0-doc
    $ sudo apt install devhelp
    $ sudo apt install gtk-3-examples
    $ sudo apt install git-all
    $ sudo apt install gedit
    $ sudo apt install at-spi2-core

---

The gtkmm library is rather complex, so no annotation of the source code is provided here. We'll discuss writing Graphical User Interfaces (GUI) in gtkmm in the middle third of CSE1325.
