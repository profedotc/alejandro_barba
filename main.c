// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"
// MAIN
int main ()
{          
	       int i = 0;
	       int aw = 0;
	       bool mw[2][SX][SY];
	       gol_init(mw);
           do {
                 printf("\033cIteration %d\n", i++);
                 gol_print(mw, aw);
                 gol_step(mw, aw);
                 aw = !aw;
           }  while (getchar() != 'q');
              return EXIT_SUCCESS;
}
