Environment Test
================

These programs are provided to test an environment that you configure yourself, to ensure it is capable of running graphical applications with g++.

You can build and run all tests by simply typing 

  ``make test`` 

at the bash command line from this directory. You should see:

* "Hello, World!" printed to the console. This tests your environment's ability to compile simple C++.
* A dialog containing "Hello, World!" and an OK button. This tests your environment's ability to display graphical dialogs.
* A window containing a button labeled "Hello, world!" which, when clicked, prints "Hello, world!" to the console. This tests your environment's ability to compile and run your gtkmm code.

To remove all intermediary and compiled files (that is, to "clean up"), type

  ``make clean``

