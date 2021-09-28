#ifndef TSP_PROBLEM
#define TSP_PROBLEM

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Problema.h"
#include "Lista.h"
#include "Estado.h"
#include "EstadoTSP.h"

class ProblemaTSP : public Problema {
   private:
    EstadoTSP* inicial;
    EstadoTSP* solucion;
    int distancia;
   
   public:
      ProblemaTSP();
      ~ProblemaTSP();
      Estado * getEstadoInicial();
      int esSolucion( Estado * );
      int heuristica(Estado *);
      int distanciaManhattan(int, int);
      Lista * getSiguientes( Estado * );      
};
#endif
