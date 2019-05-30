// HEADERS
#include <stdio.h>
#include <stdbool.h>
#include "gol.h"
// FUNCTIONS GOL
// 1st Function
void gol_init(bool mw[][SX][SY])
{
     for (int z = 0; z < 2; z++) {
         for (int x = 0; x < SX; x++) {
             for (int y = 0; y < SY; y++) {
                  mw[z][x][y] = 0;
             }     
         }
         // Initial pattern
        mw[z][0][1] = 1;
        mw[z][1][2] = 1;
        mw[z][2][0] = 1;
        mw[z][2][1] = 1;
        mw[z][2][2] = 1;
     }         
     
}
// 2nd Function
void gol_print(bool mw[][SX][SY], bool aw)
{
     for (int x = 0; x < SX; x++) {
         for (int y = 0; y < SY; y++) {
              printf("%c ", mw[aw][x][y]? '#' : '.');
         }
         printf("\n");
     }
}
// 3rd Function
// an = alive neighbors; aw2 = auxiliary world 2;
void gol_step(bool mw[][SX][SY], bool aw)
{         
	 int an = 0;
     int aw2 = !aw;
     for (int x = 0; x < SX; x++) {
         for (int y = 0; y < SY; y++) {
             an = gol_count_neighbors(mw, x, y, aw);
             if (mw[aw][x][y]) {
                    // Survival condition
                       mw[aw2][x][y] = (an == 2) || (an == 3);
             } else {      
                    // Resurrection condition
                       mw[aw2][x][y] = (an == 3);
               }
         }      
     }
}
// 4th Function
// anc = alive neighbors counter
int gol_count_neighbors(bool mw[][SX][SY], int x, int y, bool aw)
{
     int anc = -mw[aw][x][y];
     for (int i = x-1; i <= x+1; i++) {
         for (int j = x-1; j <= y+1; j++) {
         
              anc += mw[aw][i][j];
         }
     }
         return anc;     
}
// 5th Function
bool gol_get_cell(bool mw[][SX][SY], int x, int y, bool aw)
{
          if (x >= 0 && y >= 0 && x < SX && y < SY) {
              return mw[aw][x][y];
          } else {
                  return 0; 
            }
}
