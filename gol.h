// HEADERS
#include <stdbool.h>
// MACROS
// SX, SY = size of the coordinates X and Y, respectively
#ifndef _GOL_H_
#define _GOL_H_
#define SX 10
#define SY 10
// FUNCTIONS
// mw, aw = main and auxiliary worlds, respectively
void gol_init(bool mw[][SX][SY]);
void gol_print(bool mw[][SX][SY], bool aw);
void gol_step(bool mw[][SX][SY], bool aw);
int gol_count_neighbors(bool mw[][SX][SY], int x, int y, bool aw);
bool gol_get_cell(bool mw[][SX][SY], int x, int y, bool aw);
// END
#endif
