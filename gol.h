#ifndef _GOL_H_
#define _GOL_H_
// HEADERS
#include <stdbool.h>
// STRUCTURE
// ws = worlds;
struct gol
{
    bool **ws[2];
    int sx;
    int sy;
};
// FUNCTIONS
void gol_alloc(struct gol *g, int sx, int sy);
void gol_free(struct gol *g);
void gol_init(struct gol *g);
void gol_print(struct gol *g);
void gol_step(struct gol *g);
// END
#endif
