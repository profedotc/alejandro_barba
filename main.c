// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"
// MAIN
int main ()
{
        int i = 0;
        struct gol g;
        gol_alloc(&g, SX, SY);
        gol_init(&g, SX, SY);
        do 
        {
                printf("\033cIteration %d\n", i++);
                gol_print(&g, SX, SY);
                gol_step(&g);
        }   while (getchar() != 'q');
            gol_free(&g, SY);
            return EXIT_SUCCESS;
}
