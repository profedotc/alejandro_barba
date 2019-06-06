// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol_42.h"
// cw, nw = current and next worlds, respectively; w = world; ws = worlds;
// ENUMERATION
enum w_type {cw, nw};
// STATIC FUNCTIONS
static bool get_cell(const struct gol *g, int x, int y);
static int count_neighbors(const struct gol *g, int x, int y);
// FUNCTIONS
// 1st Function
void gol_init(struct gol *g)
{
    for (int x = 0; x < g->SX; x++) {
        for (int y = 0; y < g->SY; y++) { 
            g->ws[cw][x][y] = 0;
        }
    }
            // Initial pattern
            g->ws[cw][0][1] = 1;
            g->ws[cw][1][2] = 1;
            g->ws[cw][2][0] = 1;
            g->ws[cw][2][1] = 1;
            g->ws[cw][2][2] = 1;
}
// 2nd Function
void gol_print(const struct gol *g)
{
    for (int x = 0; x < g->SX; x++) {
        for (int y = 0; y < g->SY; y++) {
            printf("%c ", g->ws[cw][x][y]? '#' : '.');
        }
        printf("\n");
    }
}
// 3rd Function
// an = aive neighbors;
void gol_step(struct gol *g)
{
    bool **swap;
    for (int x = 0; x < g->SX; x++) {
        for (int y = 0; y < g->SY; y++) {
            int an = count_neighbors(g, x, y);
            if (g->ws[cw][x][y]) {
                // Survival condition
                    g->ws[nw][x][y] = (an == 2) || (an == 3);
            }   else {      
                    // Resurrection condition
                    g->ws[nw][x][y] = (an == 3);
                }
        }      
    }
swap = g->ws[cw];
g->ws[cw] = g->ws[nw];
g->ws[nw] = swap;
}
// 4th Function
bool gol_alloc(struct gol *g, int SX, int SY)
{
        for (int w = cw; w <= nw; w++) {
            g->ws[w] = malloc(SX * sizeof(bool*));
            if (!g->ws[w])
                return 0;
// r = row;
            for (int r = 0; r < SX; r++) {
                g->ws[w][r] = malloc(SY * sizeof(bool));
                if (!g->ws[w][r])
                return 0;
            }
        }
        g->SX = SX;
        g->SY = SY;
        return 1;
}
// 5th Function
void gol_free(struct gol *g)
{
    for (int w = cw; w <= nw; w++) {
        for (int r = 0; r < g->SX; r++)
            free(g->ws[w][r]);
        free(g->ws[w]);
    }
}
// STATIC FUNCTIONS
// 1st Function
static bool get_cell(const struct gol *g, int x, int y)
{
    if (x >= 0 && y >= 0 && x < g->SX && y < g->SY) {
        return g->ws[cw][x][y];
    }   else {
                return 0; 
        }
}
// 2nd Function
// anc = alive neighbors counter
static int count_neighbors(const struct gol *g, int x, int y)
{
    int anc = -get_cell(g, x, y);
        for (int i = x-1; i <= x+1; i++) {
            for (int j = x-1; j <= y+1; j++) {
                        anc ++;
            }   
        }
                return anc;     
}
