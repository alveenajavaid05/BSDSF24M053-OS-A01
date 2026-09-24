# BSDSF24M053-OS-A01
Makefile Difference:
In the multi-file build, the object files were directly linked together to create the executable. In the static-library build, the utility object files are first combined into libmyutils.a using the ar command. The main object file is then linked with this library using -Llib and -lmyutils.

The static-library Makefile therefore has an additional library target and a library variable. This separates the utility code from the main program and makes the utility functions reusable.
