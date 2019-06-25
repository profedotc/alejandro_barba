// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include "gol.h"
// MACROS
// SX, SY = size of the coordinates X and Y, respectively
#define SX 10
#define SY 20
// MAIN
int main ()
{
        int i = 0;
        struct gol g;
        if (!gol_alloc(&g, SX, SY)) {
            fprintf(stderr, "ERROR: Could not allocate memory\n");
            exit(EXIT_FAILURE);
        }
        gol_init(&g);
        do 
        {
                printf("\033cIteration %d\n", i++);
                gol_print(&g);
                gol_step(&g);
        }   while (getchar() != 'q');
            gol_free(&g);
            return EXIT_SUCCESS;
}
