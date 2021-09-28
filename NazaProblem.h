
#ifndef _NAZA_PROBLEM
#define _NAZA_PROBLEM

#include <stdlib.h>
#include<iostream>
using namespace std;

#include "Problema.h"
#include "Lista.h"
#include "Estado.h"
#include "NazaEstado.h"

class NazaProblem : public Problema {
   private:
      NazaEstado *inicial;
      NazaEstado *solucion; //el estado final
     

   public:
      NazaProblem();
      ~NazaProblem();
      Estado * getEstadoInicial(); 
      int esSolucion( Estado * ); 
      int heuristica(Estado *); 
      Lista * getSiguientes( Estado * );

};
#endif