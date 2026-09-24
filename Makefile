CC = gcc
CFLAGS = -Wall -Iinclude
PICFLAGS = -fPIC

OBJ = obj/mystrfunctions.o obj/myfilefunctions.o

LIB = lib/libmyutils.so
TARGET = bin/client_dynamic

all: $(TARGET)

$(TARGET): $(LIB) obj/main.o
	$(CC) obj/main.o -Llib -lmyutils -o $(TARGET)

$(LIB): $(OBJ)
	$(CC) -shared -o $(LIB) $(OBJ)

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/mystrfunctions.o: src/mystrfunctions.c
	$(CC) $(CFLAGS) $(PICFLAGS) -c src/mystrfunctions.c -o obj/mystrfunctions.o

obj/myfilefunctions.o: src/myfilefunctions.c
	$(CC) $(CFLAGS) $(PICFLAGS) -c src/myfilefunctions.c -o obj/myfilefunctions.o

clean:
	rm -f obj/*.o lib/libmyutils.so bin/client_dynamic

.PHONY: all clean
