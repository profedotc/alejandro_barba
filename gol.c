// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"
// CW, NW = Current and Next Worlds, respectively; w = world; ws = worlds;
// ENUMERATION
enum world_type {
        CW,
        NW,
};
// STATIC FUNCTIONS
static int count_neighbors(const struct gol *g, int x, int y);
static bool get_cell(const struct gol *g, int x, int y);
static void set_cell(struct gol *g, enum world_type wt, int x, int y, bool a);
// FUNCTIONS
// 1st Function
bool gol_alloc(struct gol *g, int sx, int sy)
{
    for (int k = CW; k <= NW; k++) {
        g->ws[k] = (bool *)malloc(sx * sy * sizeof(bool));
        if (!g->ws[k]) 
            return 0;
    }
    g->sx = sx;
    g->sy = sy;
    return 1;
}
// 2nd Function
void gol_free(struct gol *g)
{
    for (int k = CW; k <= NW; k++) {
    free(g->ws[k]);
    }
}
// 3rd Function
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
// 4th Function
void gol_print(struct gol *g)
{
    for (int x = 0; x < g->sx; x++) {
        for (int y = 0; y < g->sy; y++) {
            printf("%c ", get_cell(g, x, y)? '#' : '.');
        }
        printf("\n");
    }
}
// 5th Function
// an = aive neighbors;
void gol_step(struct gol *g)
{
    for (int x = 0; x < g->sx; x++) {
        for (int y = 0; y < g->sy; y++) {
            int an = count_neighbors(g, x, y);
            if (get_cell(g, x, y)) {
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
    
    anc += get_cell(g, x - 1, y + 1);
    anc += get_cell(g, x, y + 1);
    anc += get_cell(g, x + 1, y + 1);
    
    anc += get_cell(g, x - 1, y);
    anc += get_cell(g, x + 1, y);
    
    anc += get_cell(g, x - 1, y - 1);
    anc += get_cell(g, x, y - 1);
    anc += get_cell(g, x + 1, y - 1);
    
    return anc;         
}
// 2nd Function
static bool get_cell(const struct gol *g, int x, int y)
{
    if(x >= g->sx)
        x = 0;
    else if (x < 0)
        x = g->sx - 1;
    if(y >= g->sy)
        y = 0;
    else if (y < 0)
        y = g->sy - 1;
    return g->ws[CW][x * g->sy + y];
}
// 3rd Function
static void set_cell(struct gol *g, enum world_type wt, int x, int y, bool a)
{
    g->ws[wt][x * g->sy + y] = a;
}
