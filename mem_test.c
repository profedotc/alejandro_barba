// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include "gol.h"
// MACROS
// SX, SY = size of the coordinates X and Y, respectively;
// I = Iterations
#define I 1000
#define SX 10
#define SY 15
// MAIN
int main ()
{
    struct gol *g;
    g = gol_alloc(SX, SY);
    gol_init(g);
    for (int i = 0; i < I; i++) {
            gol_step(g);
    }
        gol_free(g);
        return EXIT_SUCCESS;
}
