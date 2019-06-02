// HEADERS
#include <stdbool.h>
// MACROS
// SX, SY = size of the coordinates X and Y, respectively
#ifndef _GOL_H_
#define _GOL_H_
#define SX 10
#define SY 10
// STRUCTURE
// w = worlds; cw = current world;
struct gol
{
    bool w[SX][SY][2];
    bool cw;
};
// FUNCTIONS
void gol_init(struct gol *g);
void gol_print(struct gol *g);
void gol_step(struct gol *g);
// END
#endif
