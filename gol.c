// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include "gol.h"
// MACRO
#define GET_CELL(g, x, y) (g->ws[wt][x * g->sy + y])
// CW, NW = Current and Next Worlds, respectively; w = world; ws = worlds;
// ENUMERATION
enum world_type {
        CW,
        NW,
};
// STATIC FUNCTIONS
static int count_neighbors(const struct gol *g, int x, int y);
static bool get_cell(const struct gol *g, enum world_type wt, int x, int y);
static void set_cell(struct gol *g, enum world_type wt, int x, int y, bool a);
// STRUCTURE
struct gol * gol_alloc(int sx, int sy)
{
    struct gol *g = (struct gol *)malloc(sizeof(struct gol));
    if (!g)
        return NULL;
    g->k = (bool *)malloc(2 * sx * sy * sizeof(bool));
    if (!g->k) {
        free(g);
        return NULL;
    }
    g->sx = sx;
    g->sy = sy;
    g->ws[CW] = g->k;
    g->ws[NW] = g->k + sx * sy;
    return g;
}
// FUNCTIONS
// 1st Function
void gol_free(struct gol *g)
{
    free(g->k);
    free(g);
}
// 2nd Function
void gol_init(struct gol *g)
{
    for (int x = 0; x < g->sx; x++) {
        for (int y = 0; y < g->sy; y++) { 
                set_cell(g, CW, x, y, 0);
        }
    }
            // Initial pattern
            set_cell(g, CW, 0, 1, 1);
            set_cell(g, CW, 1, 2, 1);
            set_cell(g, CW, 2, 0, 1);
            set_cell(g, CW, 2, 1, 1);
            set_cell(g, CW, 2, 2, 1);
}
// 3rd Function
void gol_print(struct gol *g)
{
    for (int x = 0; x < g->sx; x++) {
        for (int y = 0; y < g->sy; y++) {
            printf("%c ", get_cell(g, CW, x, y)? '#' : '.');
        }
        printf("\n");
    }
}
// 4th Function
// an = aive neighbors;
void gol_step(struct gol *g)
{
    for (int x = 0; x < g->sx; x++) {
        for (int y = 0; y < g->sy; y++) {
            int an = count_neighbors(g, x, y);
            if (get_cell(g, CW, x, y)) {
                // Survival condition
                   bool a = (an == 2) || (an == 3);
                   set_cell(g, NW, x, y, a);
            }   else {      
                    // Resurrection condition
                        bool a = an == 3;
                        set_cell(g, NW, x, y, a);
                }
        }      
    }
    bool *swap = g->ws[CW];
    g->ws[CW] = g->ws[NW];
    g->ws[NW] = swap;
}
// STATIC FUNCTIONS
// 1st Function
// anc = alive neighbors counter
static int count_neighbors(const struct gol *g, int x, int y)
{
    int anc = 0;
    
    anc += get_cell(g, CW, x - 1, y + 1);
    anc += get_cell(g, CW, x, y + 1);
    anc += get_cell(g, CW, x + 1, y + 1);
    
    anc += get_cell(g, CW, x - 1, y);
    anc += get_cell(g, CW, x + 1, y);
    
    anc += get_cell(g, CW, x - 1, y - 1);
    anc += get_cell(g, CW, x, y - 1);
    anc += get_cell(g, CW, x + 1, y - 1);
    
    return anc;         
}
// 2nd Function
static bool get_cell(const struct gol *g, enum world_type wt, int x, int y)
{
    if(x >= g->sx)
        x = 0;
    else if (x < 0)
        x = g->sx - 1;
    if(y >= g->sy)
        y = 0;
    else if (y < 0)
        y = g->sy - 1;
    return GET_CELL(g, x, y);
}
// 3rd Function
static void set_cell(struct gol *g, enum world_type wt, int x, int y, bool a)
{
    GET_CELL(g, x, y) = a;
}
