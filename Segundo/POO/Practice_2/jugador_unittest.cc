// jugador_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include <fstream>
#include <list>
#include "jugador.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Jugador, ConstructorParametrosDefecto) {
  Jugador j("33XX", "1");
  
  EXPECT_EQ("33XX", j.getDNI());
  EXPECT_EQ("1", j.getCodigo());
  EXPECT_EQ("", j.getNombre());
  EXPECT_EQ("", j.getApellidos());
  EXPECT_EQ("", j.getDireccion());
  EXPECT_EQ("", j.getLocalidad());
  EXPECT_EQ("", j.getProvincia());
  EXPECT_EQ("", j.getPais());
  EXPECT_EQ(", ", j.getApellidosyNombre());
}

TEST(Jugador, ConstructorParametros) {
  Jugador j("44XX", "2", "Carlos", "Gutierrez",30, "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  
  EXPECT_EQ("44XX", j.getDNI());
  EXPECT_EQ("2", j.getCodigo());
  EXPECT_EQ("Carlos", j.getNombre());
  EXPECT_EQ("Gutierrez", j.getApellidos());
  EXPECT_EQ("C/ Mesa 1", j.getDireccion());
  EXPECT_EQ("Aguilar", j.getLocalidad());
  EXPECT_EQ("Sevilla", j.getProvincia());
  EXPECT_EQ("España", j.getPais());
  EXPECT_EQ("Gutierrez, Carlos", j.getApellidosyNombre());
}

TEST(Jugador, setDineroygetDinero) {
  Jugador j("33XX", "1");

  EXPECT_EQ(1000, j.getDinero());
  j.setDinero(555);
  EXPECT_EQ(555, j.getDinero());
}

TEST(Jugador, setCodigoygetCodigo) {
  Jugador j("33XX", "1");

  EXPECT_EQ("1", j.getCodigo());
  j.setCodigo("55");
  EXPECT_EQ("55", j.getCodigo());
}

TEST(Jugador, setApuestasygetApuestasVacio) {
  Jugador j("33XX", "1");
  list<Apuesta> l;
  l= j.getApuestas();
  EXPECT_TRUE(l.empty());
}
TEST(Jugador, setApuestasygetApuestas) {
  Jugador j("33XX", "1");
  string nomfich=j.getDNI()+".txt";
  ofstream salida(nomfich.c_str());
  salida << 1 << "," << "10" << "," << 15<< "\n";
  salida << 2 << "," << "rojo" << "," << 25<< "\n";
  salida << 3 << "," << "par" << "," << 35<< "\n";
  salida << 4 << "," << "bajo" << "," << 45<< "\n";
  salida.close();
  list<Apuesta> l;
  j.setApuestas();
  l= j.getApuestas();
  EXPECT_EQ(4, l.size());
  list<Apuesta>::iterator i;
  i=l.begin();
  EXPECT_EQ(1, (*i).tipo);
  EXPECT_EQ("10", (*i).valor);
  EXPECT_EQ(15, (*i).cantidad);
  i++;
  EXPECT_EQ(2, (*i).tipo);
  EXPECT_EQ("rojo", (*i).valor);
  EXPECT_EQ(25, (*i).cantidad);
  i++;
  EXPECT_EQ(3, (*i).tipo);
  EXPECT_EQ("par", (*i).valor);
  EXPECT_EQ(35, (*i).cantidad);
  i++;
  EXPECT_EQ(4, (*i).tipo);
  EXPECT_EQ("bajo", (*i).valor);
  EXPECT_EQ(45, (*i).cantidad);
}

