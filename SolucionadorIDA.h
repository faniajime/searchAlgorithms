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
};
class SolucionadorIDA : public Solucionador {
   private:
    int profundidad;
    int maxProfundidad;
    int height;
    int minHeuristica;
    NodoIDA * final;

   public:
      SolucionadorIDA();
      Solucion * solucione(Problema *);
      Solucion * solucioneRec(Estado * estado, int profundidad, Solucion * solucion);
      int fcost(Problema * problema, Estado * estado, int nodos);
      int buscar(NodoIDA * n, Problema * p, int profundidad);
      Solucion * getSolucion(NodoIDA * n);
};


#endif
