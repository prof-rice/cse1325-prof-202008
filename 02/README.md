Lecture 02
==========

The files in this folder represent the anticipated
evolution of the file to be developed "live" in this lecture.
But you never know where we may wander in class!

---

To compare 2 files, use either diff (command line)
or meld (GUI, recommended if your VM isn't CPU-starved).
So, to compare 02-c_strings.cpp to 03-c++_strings.cpp:

* In a narrow terminal

``diff 02-c_strings.cpp 03-c++_strings.cpp``

* In a wide terminal

``diff -y 02-c_strings.cpp 03-c++_strings.cpp``

* In a GUI

``meld 02-c_strings.cpp 03-c++_strings.cpp``

---

To build **all** of these programs, just type ``make``.
To just build [program].cpp, type ``make [program]``.

So, ``make 40_vectors`` will compile 40_vectors.cpp into an executable named 40_vectors. Then, ``./40_vectors`` will run it.

---

Type ``make clean`` to delete all of the executables.

(NOTE: This directory uses a more generic form of Makefile that we won't cover in class.
If you want to use it, though, you must be able to explain how it works to your grader
and to me. Cruel, I know, but necessary. Otherwise, write the more explicit Makefile
that we teach you until you're ready for something more advanced. You'll thank me later.)
