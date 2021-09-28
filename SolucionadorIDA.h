#ifndef SOLUCIONADOR_IDA
#define SOLUCIONADOR_IDA
#include "Solucionador.h"
#include <iostream>
#include <list>
#include <iterator>
#include <chrono>

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
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
    

   public:
      SolucionadorIDA();
      Solucion * solucione(Problema *);
      int fcost(Problema * problema, Estado * estado, int nodos);
      int buscar(NodoIDA * n, Problema * p);
      Solucion * getSolucion(NodoIDA * n);
};


#endif
