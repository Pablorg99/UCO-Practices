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
#include <cstdlib>
#include <ctime>
#include <cmath>

// Tests the c'tor.
TEST(Dados, Constructor) {
  Dados d;
  
  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma());
  
}

// Tests operación lanzamiento
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

// Tests operación suma
TEST(Dados, getSuma) {
  Dados d;
  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
  d.lanzamiento();
  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
  d.lanzamiento();
  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
}

// Tests modificadores
TEST(Dados, Modificadores) {
  Dados d;
  int r1, r2;
  EXPECT_FALSE(d.setDado1(9));
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_FALSE(d.setDado2(-9));
  d.setDado1(3);
  EXPECT_EQ(3, d.getDado1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
  srand(time(NULL));
  for (int i=0;i<100;i++)
  {
    r1=(rand()%6)+1;
    r2=(rand()%6)+1;
    EXPECT_TRUE(d.setDado1(r1));
    EXPECT_TRUE(d.setDado2(r2));
    EXPECT_EQ(r1, d.getDado1());
    EXPECT_EQ(r2, d.getDado2());
  }
}

TEST(Dados, getDiferencia) {
  Dados d;
  int r1,r2;
  d.setDado1(2);
  d.setDado2(2);
  EXPECT_EQ(0, d.getDiferencia());
  d.setDado1(2);
  d.setDado2(3);
  EXPECT_EQ(1, d.getDiferencia());
  d.setDado1(3);
  d.setDado2(2);
  EXPECT_EQ(1, d.getDiferencia());
  d.setDado1(1);
  d.setDado2(6);
  EXPECT_EQ(5, d.getDiferencia());
  d.setDado1(6);
  d.setDado2(1);
  EXPECT_EQ(5, d.getDiferencia());
  srand(time(NULL));
  for (int i=0;i<100;i++)
  {
    r1=(rand()%6)+1;
    r2=(rand()%6)+1;
    d.setDado1(r1);
    d.setDado2(r2);
    EXPECT_EQ(abs(r1-r2), d.getDiferencia());
  }
}

TEST(Dados, getLanzamientos) {
  Dados d;
  EXPECT_EQ(0, d.getLanzamientos1());
  EXPECT_EQ(0, d.getLanzamientos2());
  d.setDado1(2);
  d.setDado2(2);
  d.lanzamiento();
  EXPECT_EQ(2, d.getLanzamientos1());
  EXPECT_EQ(2, d.getLanzamientos2());
  for (int i=0;i<5;i++) d.setDado1(4);
  for (int i=0;i<10;i++) d.setDado2(4);
  EXPECT_EQ(7, d.getLanzamientos1());
  EXPECT_EQ(12, d.getLanzamientos2());
}

TEST(Dados, getMedia) { // Un buen test con random()
  Dados d;
  int i, r1, r2, s1=0, s2=0;
  EXPECT_NEAR(0.0, d.getMedia1(), 0.001); // No usar EXPECT_EQ con floats
  EXPECT_NEAR(0.0, d.getMedia2(), 0.001); // No se puede usar == con floats
  d.setDado1(2);
  d.setDado2(2);
  EXPECT_NEAR(2.0, d.getMedia1(), 0.001);
  EXPECT_NEAR(2.0, d.getMedia2(), 0.001);
  srand(time(NULL));
  s1+=2;
  s2+=2;
  d.lanzamiento();
  s1+=d.getDado1();
  s2+=d.getDado2();
  for (i=0;i<10;i++){
    r1=rand()%6+1;
    r2=rand()%6+1;
    s1+=r1;
    s2+=r2;
    d.setDado1(r1);
    d.setDado2(r2);
  }
  EXPECT_NEAR((s1/12.0), d.getMedia1(), 0.001);
  EXPECT_NEAR((s2/12.0), d.getMedia2(), 0.001);
}

TEST(Dados, getUltimos1) {
  Dados d;
  int i;
  int v1[5], v2[5];
  for (i=1;i<6;i++) d.setDado1(i);
  for (i=1;i<6;i++) d.setDado2(i);
  d.getUltimos1(v1);
  d.getUltimos2(v2);
  for (i=0;i<5;i++) EXPECT_EQ(5-i,v1[i]);
  for (i=0;i<5;i++) EXPECT_EQ(5-i,v2[i]);
}

TEST(Dados, getUltimos2) {
  Dados d;
  int i;
  int v1[5], v2[5], v1t[5], v2t[5];
  for (i=(rand()%100)+6;i>0;i--){
      d.setDado1(1);
      d.setDado2(1);
      }
  for (i=0;i<5;i++){
      d.setDado1(v1t[i]=rand()%6+1);
      d.setDado2(v2t[i]=rand()%6+1);
      }
  d.getUltimos1(v1);
  d.getUltimos2(v2);
  for (i=0;i<5;i++) EXPECT_EQ(v1t[i],v1[4-i]);
  for (i=0;i<5;i++) EXPECT_EQ(v2t[i],v2[4-i]);
}

TEST(Dados, getUltimos3) { // Otro buen test con random()
  Dados d;
  int i;
  int v1a[5], v2a[5];
  int v1b[5], v2b[5];
  for (i=0;i<5;i++) {
    v1a[i]=(rand()%6)+1;
    v2a[i]=(rand()%6)+1;
    d.setDado1(v1a[i]);
    d.setDado2(v2a[i]);
  }
  d.getUltimos1(v1b);
  d.getUltimos2(v2b);
  for (i=0;i<5;i++) EXPECT_EQ(v1a[i],v1b[4-i]);
  for (i=0;i<5;i++) EXPECT_EQ(v2a[i],v2b[4-i]);
}
