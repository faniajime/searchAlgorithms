#ifndef SOLUCIONADOR_IDA
#define SOLUCIONADOR_IDA
#include "Solucionador.h"
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Nodo{
    Nodo * padre;
    Estado * estado;
};
class SolucionadorIDA : public Solucionador {
   private:
    int profundidad;
    int maxProfundidad;
    int height;
    int minheuristica;
    Nodo * final;

   public:
      SolucionadorIDA();
      Solucion * solucione(Problema *);
      Solucion * solucioneRec(Estado * estado, int profundidad, Solucion * solucion);
      int fcost(Problema * problema, Estado * estado, int nodos);
      int buscar(Nodo * n, Problema * p, int profundidad);
      Lista * getSolucion(Nodo * n);
      Solucion * getSolucion(Nodo * n);
};


#endif
