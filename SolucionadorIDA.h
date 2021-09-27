#ifndef SOLUCIONADOR_IDA
#define SOLUCIONADOR_IDA
#include "Solucionador.h"
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class NodoIDA{
    public:
        NodoIDA * padre;
        Estado * estado;
        int nivel;
};
class SolucionadorIDA : public Solucionador {
   private:
    int profundidad;
    int minHeuristica;
    NodoIDA * final;
    int globalFound;

   public:
      SolucionadorIDA();
      Solucion * solucione(Problema *);
      int fcost(Problema * problema, Estado * estado, int nodos);
      int buscar(NodoIDA * n, Problema * p);
      Solucion * getSolucion(NodoIDA * n);
};


#endif
