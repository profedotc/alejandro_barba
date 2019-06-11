// MACROS
// SX, SY = size of the coordinates X and Y, respectively
#ifndef _GOL_H_
#define _GOL_H_
#define SX 10
#define SY 20
// STRUCTURE
// ws = worlds;
struct gol
{
    bool **ws[2];
};
// FUNCTIONS
void gol_alloc(struct gol *g, int sx, int sy);
void gol_free(struct gol *g, int sy);
void gol_init(struct gol *g, int sx, int sy);
void gol_print(struct gol *g, int sx, int sy);
void gol_step(struct gol *g);
// END
#endif
