CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all debug release clean

all: debug

release : CFLAGS += -g -O3
release : exe

debug : CFLAGS += -g -O0
debug : exe

exe: main.o gol.o
		$(CC) main.o gol.o -o exe
        
main.o: main.c gol.h
		$(CC) -c main.c
        
gol.o: gol.c gol.h
		$(CC) -c gol.c
        
clean:
		rm *.o
		rm exe
