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
            gol_init(&g);
            do 
            {
                printf("\033cIteration %d\n", i++);
                gol_print(&g);
                gol_step(&g);
            }   while (getchar() != 'q');
            return EXIT_SUCCESS;
}
