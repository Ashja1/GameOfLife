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

TEST_CASE("Check live cells die with overpopulation"){

  aliveness data1[] = {1,1,1,0,
                       1,1,1,0,
                       1,1,1,0,
                       0,0,0,0};

  aliveness data2[] = {1,1,1,0,
                       1,1,1,0,
                       1,1,0,0,
                       0,0,0,0};

  aliveness data3[] = {1,1,1,0,
                       1,1,0,0,
                       1,1,0,0,
                       0,0,0,0};

  aliveness data4[] = {1,1,0,0,
                       1,1,0,0,
                       1,1,0,0,
                       0,0,0,0};

  aliveness data5[] = {1,1,0,0,
                       1,1,0,0,
                       1,0,0,0,
                       0,0,0,0};


  
  world1.PopulateFromArray(data1, array_length);
  world1.Update();

  
  world2.PopulateFromArray(data2, array_length);
  world2.Update();

  
  world3.PopulateFromArray(data3, array_length);
  world3.Update();

  
  world4.PopulateFromArray(data4, array_length);
  world4.Update();

  
  world5.PopulateFromArray(data5, array_length);
  world5.Update();

  REQUIRE(world1.Grid()[1][1] == 0);
  REQUIRE(world2.Grid()[1][1] == 0);
  REQUIRE(world3.Grid()[1][1] == 0);
  REQUIRE(world4.Grid()[1][1] == 0);
  REQUIRE(world5.Grid()[1][1] == 0);

}
TEST_CASE("Check live cells stay alive with correct neighbor number"){

  aliveness data1[] = {1,1,0,0,
                       1,1,0,0,
                       0,0,0,0,
                       0,0,0,0};

  aliveness data2[] = {1,1,0,0,
                       0,1,0,0,
                       0,0,0,0,
                       0,0,0,0};

 
  
  world1.PopulateFromArray(data1, array_length);
  world1.Update();

  
  world2.PopulateFromArray(data2, array_length);
  world2.Update();

  REQUIRE(world1.Grid()[1][1] == 1);
  REQUIRE(world2.Grid()[1][1] == 1);

}
TEST_CASE("Check dead cells stay dead unless 3 live neighbors"){

  aliveness data1[] = {0,0,0,0,
                       0,0,0,0,
                       0,0,0,0,
                       0,0,0,0};

  aliveness data2[] = {0,1,0,0,
                       0,0,0,0,
                       0,0,0,0,
                       0,0,0,0};

  aliveness data3[] = {1,1,0,0,
                       0,0,0,0,
                       0,0,0,0,
                       0,0,0,0};

  aliveness data4[] = {1,1,0,0,
                       1,0,0,0,
                       0,0,0,0,
                       0,0,0,0};


  
  world1.PopulateFromArray(data1, array_length);
  world1.Update();

  
  world2.PopulateFromArray(data2, array_length);
  world2.Update();

  
  world3.PopulateFromArray(data3, array_length);
  world3.Update();

  
  world4.PopulateFromArray(data4, array_length);
  world4.Update();

  REQUIRE(world1.Grid()[1][1] == 0);
  REQUIRE(world2.Grid()[1][1] == 0);
  REQUIRE(world3.Grid()[1][1] == 0);
  REQUIRE(world4.Grid()[1][1] == 1);

}
TEST_CASE("Check Life edge behaviour"){

  aliveness data1[] = {0,0,0,0,
                       0,0,0,0,
                       0,0,0,0,
                       0,0,0,0};

  aliveness data2[] = {0,1,0,0,
                       0,0,0,0,
                       0,0,0,0,
                       0,0,0,0};

  aliveness data3[] = {1,1,0,0,
                       0,0,0,0,
                       0,0,0,0,
                       1,1,0,0};

  aliveness data4[] = {1,1,0,1,
                       1,0,0,0,
                       0,0,0,0,
                       0,0,1,1};


  
  world1.PopulateFromArray(data1, array_length);
  world1.Update();

 
  world2.PopulateFromArray(data2, array_length);
  world2.Update();

  
  world3.PopulateFromArray(data3, array_length);
  world3.Update();

  
  world4.PopulateFromArray(data4, array_length);
  world4.Update();

  REQUIRE(world1.Grid()[0][1] == 0);
  REQUIRE(world2.Grid()[0][1] == 0);
  REQUIRE(world3.Grid()[0][1] == 1);
  REQUIRE(world4.Grid()[0][0] == 0);

}
TEST_CASE("Check Life member functions"){

  aliveness data1[] = {0,0,0,0,
                       0,0,0,0,
                       0,0,0,0,
                       0,0,0,0};
  
  world1.PopulateFromArray(data1, array_length);

  for (int x=0;x<world1.Sizex();x++) {
    for (int y=0;y<world1.Sizey();y++) {
      REQUIRE(world1.Grid()[x][y] == 0);
    }
  }

  REQUIRE(world1.Sizex() == 4);
  REQUIRE(world1.Sizey() == 4);
  REQUIRE(world1.Size() == 16);

}
