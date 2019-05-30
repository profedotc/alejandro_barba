// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// MACROS
// SX, SY = size of the coordinates X and Y, respectively
#define SX 10
#define SY 10
// FUNCTIONS
// mw, aw = main and auxiliary worlds, respectively
void gol_init(bool mw[][SX][SY]);
void gol_print(bool mw[][SX][SY], bool aw);
void gol_step(bool mw[][SX][SY], bool aw);
int gol_count_neighbors(bool mw[][SX][SY], int x, int y, bool aw);
bool gol_get_cell(bool mw[][SX][SY], int x, int y, bool aw);
// Parts of the task
// 1st Part
int main ()
{          
	       int i = 0;
	       int aw = 0;
	       bool mw[2][SX][SY];
	       gol_init(mw);
           do {
                 printf("\033cIteration %d\n", i++);
                 gol_print(mw, aw);
                 gol_step(mw, aw);
                 aw = !aw;
           }  while (getchar() != 'q');
              return EXIT_SUCCESS;
}
// 2nd Part
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
// 3rd Part
void gol_print(bool mw[][SX][SY], bool aw)
{
     for (int x = 0; x < SX; x++) {
         for (int y = 0; y < SY; y++) {
              printf("%c ", mw[aw][x][y]? '#' : '.');
         }
         printf("\n");
     }
}
// 4th Part
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
// 5th Part
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
// 6th Part
bool gol_get_cell(bool mw[][SX][SY], int x, int y, bool aw)
{
          if (x >= 0 && y >= 0 && x < SX && y < SY) {
              return mw[aw][x][y];
          } else {
                  return 0; 
            }
}
