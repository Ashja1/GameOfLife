#include <catch.hpp>
#include "Life.h"

const int array_length =  16; // sieof(sizeof(data1) / sizeof(aliveness))
Life world1(4,4);
Life world2(4,4);
Life world3(4,4);
Life world4(4,4);
Life world5(4,4);

TEST_CASE("Check live cells die with underpopulation"){

  aliveness data1[] = {0,0,0,0,
                       0,1,0,0,
                       0,0,0,0,
                       0,0,0,0};

  aliveness data2[] = {0,1,0,0,
                       0,1,0,0,
                       0,0,0,0,
                       0,0,0,0};
  
  
  
  world1.PopulateFromArray(data1, array_length);
  world1.Update();

  
  world2.PopulateFromArray(data2, array_length);
  world2.Update();

  for (int x=0;x<world1.Sizex();x++) {
    for (int y=0;y<world1.Sizey();y++) {
      REQUIRE(world1.Grid()[x][y] == 0);
    }
  }

  for (int x=0;x<world2.Sizex();x++) {
    for (int y=0;y<world2.Sizey();y++) {
      REQUIRE(world2.Grid()[x][y] == 0);
    }
  }

}

