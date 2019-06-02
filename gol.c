// HEADERS
#include <stdio.h>
#include <stdbool.h>
#include "gol.h"
// FUNCTIONS GOL
// 1st Function
// w = worlds; cw = current world;
void gol_init(struct gol *g)
{
    for (int x = 0; x < SX; x++) {
        for (int y = 0; y < SY; y++) {
            g->w[x][y][0] = 0;
            // Initial pattern
            g->w[0][1][0] = 1;
            g->w[1][2][0] = 1;
            g->w[2][0][0] = 1;
            g->w[2][1][0] = 1;
            g->w[2][2][0] = 1;
        }
    }
    g->cw = 0;
}
// 2nd Function
void gol_print(struct gol *g)
{
    for (int x = 0; x < SX; x++) {
        for (int y = 0; y < SY; y++) {
            printf("%c ", g->w[g->cw][x][y]? '#' : '.');
        }
        printf("\n");
    }
}
// 3rd Function
// an = alive neighbors; aw = auxiliary world;
void gol_step(struct gol *g)
{
    int aw = !g->cw;
    for (int x = 0; x < SX; x++) {
        for (int y = 0; y < SY; y++) {
            int an = gol_count_neighbors(g, x, y);
            if (g->w[g->cw][x][y]) {
                // Survival condition
                    g->w[aw][x][y] = (an == 2) || (an == 3);
            }   else {      
                    // Resurrection condition
                    g->w[aw][x][y] = (an == 3);
                }
        }      
    }
    g->cw = !g->cw;
}
// 4th Function
// anc = alive neighbors counter
int gol_count_neighbors(struct gol *g, int x, int y)
{
    int anc = 0;
        for (int i = x-1; i <= x+1; i++) {
            for (int j = x-1; j <= y+1; j++) {
                if (gol_get_cell(g, i, j)) {
                    if ((i == x && j != y) || (i != x && j == y) || (i != x && j != y)) {
                        anc ++;
                    }
                }
            }
        }
                return anc;     
}
// 5th Function
bool gol_get_cell(struct gol *g, int x, int y)
{
    if (x >= 0 && y >= 0 && x < SX && y < SY) {
        return g->w[g->cw][x][y];
    }   else {
                return 0; 
        }
}
