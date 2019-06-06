CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all debug release clean

// Se crea un makefile para compilar y limpiar el repositorio

all: debug

release: CFLAGS += -O3
release: exe

debug: CFLAGS += -g -O0
debug: exe

exe: main.o gol.o
		$(CC) main.o gol.o -o exe
main.o: main.c gol.h
		$(CC) -c main.c
gol.o: gol.h gol.c
		$(CC) -c gol.c
clean:
		rm *.o exe
