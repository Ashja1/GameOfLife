#include "Life.h"

Life::Life(int sizex, int sizey):
day(0),
sizex(sizex),
sizey(sizey),
grid(sizex,vector<aliveness>(sizey)),
next_grid(sizex,vector<aliveness>(sizey)),
alive(true),
dead(false)
{

}

void Life::Populate(int seed){
  srand(seed);
  for (int x=0;x<sizex;x++) {
    for (int y=0;y<sizey;y++) {
        grid[x][y] = rand()%2;
    }
  }
}

void Life::PopulateFromArray(aliveness data[],int array_length){
  assert(sizex*sizey == array_length);

  for (int x=0;x<sizex;x++) {
    for (int y=0;y<sizey;y++) {
        grid[x][y] = data[y + (sizey*x)];
    }
  }
}


