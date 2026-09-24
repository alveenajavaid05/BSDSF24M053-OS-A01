# BSDSF24M053-OS-A01
# Makefile Difference:
In the multi-file build, the object files were directly linked together to create the executable. In the static-library build, the utility object files are first combined into libmyutils.a using the ar command. The main object file is then linked with this library using -Llib and -lmyutils.

The static-library Makefile therefore has an additional library target and a library variable. This separates the utility code from the main program and makes the utility functions reusable.

# Purpose of ar and ranlib
The ar command is used to create and manage static libraries. It combines object files such as mystrfunctions.o and myfilefunctions.o into libmyutils.a.

ranlib creates or updates the index of symbols in a static library. Modern versions of ar with the rcs options normally create the required index automatically, so a separate ranlib command is often not necessary.

# nm and static linking
When nm is used on client_static, symbols such as mystrlen, mystrcpy, wordCount and mygrep can be found in the executable.

This demonstrates that the required code from the static library was included in the executable during linking. The executable therefore contains the required library code instead of depending on a separate libmyutils.a file at runtime.

