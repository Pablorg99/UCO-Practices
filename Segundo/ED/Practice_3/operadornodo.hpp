#ifndef __OPERADORNODO_HPP__
#define __OPERADORNODO_HPP__

/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
#include <iostream>
#include <fstream>  //Para los flujos de entrada/salida en ficheros.
#include <vector>  //Para usar vector de la stl

using namespace std;

namespace ed
{
  /*!\brief Interfaz para definir operaciones sobre un nodo de un Arbol.

  La clases derivadas de OperadorNodo definirán operaciones para el tratamiento
  de los nodos de un Arbol cuando se realiza un recorrido sobre el mismo.

  \arg G define el campo de información de los nodos del Arbol.
  */
  template<class G>
  class OperadorNodo
  {
  public:
    /*!\brief Aplica una operacion al campo de informacion de un nodo.
    \arg[in] info es el campo de informacion a ser procesado.
    \return true si se debe seguir procesando nodos. Falso en caso contrario.
    */
    virtual bool aplicar(const G & info) = 0;
  };

  //Clase para que el tratamiento de cada nodo sea escribir su campo informativo
  template<class G>
  class EscribirNodo: public OperadorNodo<G>
  {
  public:
    EscribirNodo()
    {};
    ~EscribirNodo()
    {};
    bool aplicar(const G &info)
    {
      cout << info << "  ";
			return true;
    }
  };

  //Clase para que el tratamiento de cada nodo sea almacenarlo en un vector de la stl
  template<class G>
  class AlmacenarNodo: public OperadorNodo<G>
  {
  public:
    AlmacenarNodo()
    {};
    ~AlmacenarNodo()
    {};
    bool aplicar(const G &info)
    {
      _v.push_back(info);
			return true;
    };
    const vector<G> & vectorNodos()
    {
      return _v;
    };

  private:
    vector<G> _v;
  };

} //namespace ed

#endif //__OPERADORNODO_HPP__
