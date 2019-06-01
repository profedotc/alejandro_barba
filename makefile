.PHONY: all clean

// Se crea un makefile para compilar y limpiar el repositorio
all: exe

exe: main.o gol.o
		gcc main.o gol.o -o exe
main.o: main.c gol.h
		gcc -c main.c
gol.o: gol.h gol.c
		gcc -c gol.c
clean:
		rm *.o exe
