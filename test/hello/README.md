C++ Compiler Test
=================

To build the code in main.cpp, use this command in lxterminal:

  ``g++ --std=c++17 hello.cpp``

(Hint: You can select the above command in the editor with your mouse, then point to the terminal window and click the MIDDLE mouse button to paste it!)

By default, this creates an executable named a.out. To run it, use 

  ``./a.out``

The leading "./" just means "in the current directory". Unlike Windows, Linux will NOT run programs in the current directory without the "./". This is a security feature.

---

The more common way to build the code is to use a "Makefile". The Makefile tells a tool called "make" how to build the program, so you don't have to remember. (Sooner than you think, building your code will become rather complicated. You and your TA will REALLY appreciate the Makefile!)

To build using a makefile, just type:

  ``make``

Easy, no?  If you want to delete all of the build products and start over, first "clean" the directory, then run make again. Use these two commands:

  ``make clean``
  ``make``

Since commands can be separated on a single line using ;, you can also do this:

  ``make clean ; make``

---

Annotated hello.cpp:

```

// Two slashes starts a comment, which is ignored by g++.

// This includes the "Input Output Stream" library for use in this file
#include <iostream>

// This allows us to just type "cout" instead of a more complicated name
using namespace std;

// As with C, all programs run function main() first
int main() {

// The "stream" operator is "<<".  This line streams the text "Hello, world!"
//   to the "character output" object, followed by an "end of line" character
  cout << "Hello, world!" << endl;
}

```

---

Annotated Makefile

```

# A single pound (hash) starts a comment, which is ignored by make

# Variables in a Makefile are usually all capital letters. Some have
#   special meanings. This one, CXXFLAGS, contains options for the g++
#   compiler. We add the flag "--std=c++17", which tell g++ to enforce
#   the C++ standard released in 2017.
CXXFLAGS += --std=c++17

# Makefiles are not programs - they are lists of rules. This one means:
#   To "make hello", first check to see if the file "hello.cpp" has been 
#   modified since the program "hello" was last built.
# If not, then do nothing.
# If so, then run the bash command "g++ --std=c++17 -o hello hello.cpp".
hello: hello.cpp
	$(CXX) $(CXXFLAGS) -o hello hello.cpp

# Above you see two Makefile variables being used:
#   $(CXXFLAGS) we modified earlier - it's the options for g++.
#   $(CXX) has its default value of "g++", though we could change it
#      if we wanted to do so (e.g., we have a new version of g++ installed
#      that we want to use instead of the default version).
# You also see a new option for g++. "-o hello" tells g++ to name the
#   program it builds "hello" instead of a.out.

# Here's another rule.
#   To "make clean", we don't need to check any dates, since "clean" has
#   no files listed after the colon. It always runs the bash command:
#     rm -f hello hello.o
# The "-" before rm tells make to ignore any errors.
# "rm" is "remove", the bash command to delete one or more files.
# "-f" is the "force" option for rm, so that it never asks "Are you sure?"
#   and won't display an error if a file has already been deleted.
# "a.out" is the program we built manually.
# "hello" is the program we built with "make hello", to be removed.
# "hello.o" is the "object" file for hello.cpp, basically a partially
#   compiled version of hello.cpp. We also remove it.
clean:
	-rm -f a.out hello hello.o

# You may notice above that in a Makefile, the bash commands ALWAYS start
#   with a TAB character (not 8 spaces!). This is a requirement for a
#   Makefile, not for bash.

```

