CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all debug release clean

all: debug

release : CFLAGS += -g -O3
release : exe

debug : CFLAGS += -g -O0
debug : exe

exe: main_42.o gol_42.o
		$(CC) main_42.o gol_42.o -o exe
        
main_42.o: main_42.c gol_42.h
		$(CC) -c main_42.c
        
gol_42.o: gol_42.c gol_42.h
		$(CC) -c gol_42.c
        
clean:
		rm *.o
		rm exe
