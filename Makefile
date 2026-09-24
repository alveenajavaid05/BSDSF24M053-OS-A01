CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/mystrfunctions.c src/myfilefunctions.c
OBJ = obj/mystrfunctions.o obj/myfilefunctions.o

LIB = lib/libmyutils.a
TARGET = bin/client_static

all: $(TARGET)

$(TARGET): $(LIB) obj/main.o
	$(CC) obj/main.o -Llib -lmyutils -o $(TARGET)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/mystrfunctions.o: src/mystrfunctions.c
	$(CC) $(CFLAGS) -c src/mystrfunctions.c -o obj/mystrfunctions.o

obj/myfilefunctions.o: src/myfilefunctions.c
	$(CC) $(CFLAGS) -c src/myfilefunctions.c -o obj/myfilefunctions.o

clean:
	rm -f obj/*.o lib/libmyutils.a bin/client_static

.PHONY: all clean
