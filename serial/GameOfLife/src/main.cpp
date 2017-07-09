#include <iostream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <string>
#include "Life.h"

using namespace std;

float time_calc(clock_t begin, clock_t end){
  float total_time = (end - begin)/static_cast<float>(CLOCKS_PER_SEC);
  return total_time;
}

int main(int argc, char **argv){
  clock_t start = clock();

  int sizex;
  int sizey;
  int EndOfDays;
  bool Pseudorandom;
  bool verbose;

  
  sizex = 100;
  sizey = 100;
  EndOfDays = 100;
   

  int seed;
  ofstream outfile("output.txt");

  cout << "Running the Game of Life!" << endl;

 
    seed = 100; // Pseudorandom seed
  

  Life gameoflife(sizex,sizey);
  gameoflife.Populate(seed);

  gameoflife.WriteHeader(outfile,EndOfDays);
  while(gameoflife.Day() < EndOfDays){
    gameoflife.Record(outfile);
    gameoflife.Update();
  }
  clock_t finish = clock();
  
  cout << "The total time taken was " << time_calc(start,finish) << " seconds\n";
  
  return EXIT_SUCCESS;
}
