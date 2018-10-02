//FILE PROVIDED BY THE UNIVERSITY (Modified by me)


// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "dados.h"
#include "gtest/gtest.h"

// Tests the c'tor.
TEST(Dados, Constructor) {
  Dados d;

  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma());

}

// Test operación lanzamiento
TEST(Dados, Lanzamiento) {
  Dados d;

  for (int i=0; i<100; i++){
  d.lanzamiento();
  EXPECT_GT(d.getDado1(), 0);
  EXPECT_LT(d.getDado1(), 7);
  EXPECT_GT(d.getDado2(), 0);
  EXPECT_LT(d.getDado2(), 7);
}

}

// Test operación suma
TEST(Dados, Suma) {
  Dados d;

  EXPECT_EQ(d.getDado1() + d.getDado2(), d.getSuma());
}

//Test operación diferencia
TEST(Dados, Resta) {
  Dados d;

  d.setDado1(4);
  d.setDado2(2);
  EXPECT_EQ(2, d.getDiferencia());
  d.setDado1(2);
  d.setDado2(5);
  EXPECT_EQ(3, d.getDiferencia());
  d.setDado1(2);
  d.setDado2(2);
  EXPECT_EQ(0, d.getDiferencia());
}

// Test modificadores
TEST(Dados, Modificadores) {
  Dados d;

  EXPECT_FALSE(d.setDado1(9));
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_FALSE(d.setDado2(-9));
  d.setDado1(3);
  EXPECT_EQ(3, d.getDado1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
}

//Test get Lanzamientos
TEST(Dados, Lanzamientos) {
  Dados d;

  EXPECT_EQ(0, d.getLanzamientos1());
  EXPECT_EQ(0, d.getLanzamientos2());
  d.lanzamiento();
  EXPECT_EQ(1, d.getLanzamientos1());
  EXPECT_EQ(1, d.getLanzamientos2());
  d.setDado1(4);
  EXPECT_EQ(2, d.getLanzamientos1());
  EXPECT_EQ(1, d.getLanzamientos2());
  d.setDado1(7);
  EXPECT_EQ(2, d.getLanzamientos1());
  EXPECT_EQ(1, d.getLanzamientos2());
  d.setDado2(4);
  EXPECT_EQ(2, d.getLanzamientos1());
  EXPECT_EQ(2, d.getLanzamientos2());
  d.setDado2(7);
  EXPECT_EQ(2, d.getLanzamientos1());
  EXPECT_EQ(2, d.getLanzamientos2());
}

//Tes para la media
TEST(Dados, media) {
  Dados d;

  EXPECT_NEAR(0, d.getMedia1(), 0);
  EXPECT_NEAR(0, d.getMedia2(), 0);
  d.setDado1(2);
  d.setDado2(4);
  EXPECT_NEAR(2, d.getMedia1(), 0);
  EXPECT_NEAR(4, d.getMedia2(), 0);
  d.setDado1(3);
  d.setDado2(5);
  EXPECT_NEAR(2.5, d.getMedia1(), 0);
  EXPECT_NEAR(4.5, d.getMedia2(), 0);
  for (int i = 0; i < 1000; i++) {
    d.lanzamiento();
  }
  EXPECT_NEAR(3.5, d.getMedia1(), 0.2);
  EXPECT_NEAR(3.5, d.getMedia2(), 0.2);
}

//Test para getUltimos

TEST (Dados, 5_ultimos) {
  Dados d;
  int v1[5], v2[5];

  EXPECT_EQ (1, d.getDado1());
  EXPECT_EQ (1, d.getDado2());
  d.getUltimos1(v1);
  d.getUltimos2(v2);
  EXPECT_EQ(1, v1[0]);
  EXPECT_EQ(1, v2[0]);
  EXPECT_EQ(0, v1[3]);
  EXPECT_EQ(0, v2[2]);
  //set (from last to first 1, 4, 2, 5, 3) to dice 1
  d.setDado1(3);
  d.setDado1(5);
  d.setDado1(2);
  d.setDado1(4);
  d.setDado1(1);
  //set (from last to first 3, 2, 4, 6) to dice 2
  d.setDado2(6);
  d.setDado2(4);
  d.setDado2(3);
  d.setDado2(2);
  d.getUltimos1(v1);
  d.getUltimos2(v2);
  EXPECT_EQ(1, v1[0]);
  EXPECT_EQ(4, v1[1]);
  EXPECT_EQ(2, v1[2]);
  EXPECT_EQ(5, v1[3]);
  EXPECT_EQ(3, v1[4]);
  EXPECT_EQ(3, v2[0]);
  EXPECT_EQ(2, v2[1]);
  EXPECT_EQ(4, v2[2]);
  EXPECT_EQ(6, v2[3]);
  EXPECT_EQ(1, v2[4]);
}
