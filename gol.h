// HEADERS
#include <stdbool.h>
// MACROS
// SX, SY = size of the coordinates X and Y, respectively
#ifndef _GOL_H_
#define _GOL_H_
// STRUCTURE
// ws = worlds;
struct gol
{
    int SX;
    int SY;
    bool **ws[2];
};
// FUNCTIONS
void gol_init(struct gol *g);
void gol_print(const struct gol *g);
void gol_step(struct gol *g);
bool gol_alloc(struct gol *g, int SX, int SY);
void gol_free(struct gol *g);
// END
#endif
