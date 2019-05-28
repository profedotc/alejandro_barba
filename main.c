// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// MACROS
// sx, sy = size of the coordinates x and y, respectively
#define sx 10
#define sy 10

// FUNCTIONS
// mw, aw = main and auxiliary worlds, respectively
void gol_init(int mw[sx][sy]);
void gol_print(int mw[sx][sy]);
void gol_step(int mw[sx][sy], int aw[sx][sy]);
int gol_count_neighbors(int mw[sx][sy], int x, int y);
bool gol_get_cell(int mw[sx][sy], int x, int y);
void gol_copy(int mw[sx][sy], int aw[sx][sy]);

// Parts of the task

// 1st Part
int main ()
{          
	       int i = 0;
	       
           int mw[sx][sy];
           int aw[sx][sy];
           
           gol_init(mw);
           
           do {
                 printf("\033cIteration %d\n", i++);
                 gol_print(mw);
                 gol_step(mw, aw);

           }  while (getchar() != 'q');
              
              return EXIT_SUCCESS;
}

// 2nd Part
void gol_init(int mw[sx][sy])
{
     for (int x = 0; x < sx; x++) {
     for (int y = 0; y < sy; y++) {
         mw[x][y] = 0;
     }     
     }         
     // Initial pattern
        mw[0][1] = 1;
        mw[1][2] = 1;
        mw[2][0] = 1;
        mw[2][1] = 1;
        mw[2][2] = 1;
}

// 3rd Part
void gol_print(int mw[sx][sy])
{
     for (int x = 0; x < sx; x++) {
     for (int y = 0; y < sy; y++) {
         printf("%c ", mw[x][y]? '#' : '.');
     }
         printf("\n");
     }
}

// 4th Part
// an = alive neighbors
void gol_step(int mw[sx][sy], int aw[sx][sy])
{         
	 int an = 0;
     
     for (int x = 0; x < sx; x++) {
     for (int y = 0; y < sy; y++) {
         
         an = gol_count_neighbors(mw, x, y);
         
         if (mw[x][y]) {
                // Survival condition
                   aw[x][y] = (an == 2) || (an == 3);
         } else {      
                // Resurrection condition
                   aw[x][y] = (an == 3);
           }
     }      
     }
     gol_copy(aw, mw);
}

// 5th Part
// anc = alive neighbors counter
int gol_count_neighbors(int mw[sx][sy], int x, int y)
{
     int anc = -mw[x][y];
     
     for (int i = x-1; i <= x+1; i++) {
     for (int j = x-1; j <= y+1; j++) {
         
         anc += mw[i][j];
     }
     }
     return anc;     
}

// 6th Part
bool gol_get_cell(int mw[sx][sy], int x, int y)
{
          if (x >= 0 && y >= 0 && x < sx && y < sy) {
             return mw[x][y];
          } else {
                  return 0; 
            }
}

// 7th Part
void gol_copy(int mw[sx][sy], int aw[sx][sy])
{
     for (int x = 0; x < sx; x++) {
     for (int y = 0; y < sy; y++) {
                          
     mw[x][y] = aw[x][y];
     
     }
     }
}
