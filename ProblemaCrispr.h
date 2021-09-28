/**
 * Clase Problema Crispr
 * 
 * @author Fabiola jimenez
 */

#ifndef _CRISPR_PROBLEM
#define _CRISPR_PROBLEM

#include <stdlib.h>
#include<iostream>
using namespace std;

#include "Problema.h"
#include "Lista.h"
#include "Estado.h"
#include "EstadoCrispr.h"

class ProblemaCrispr : public Problema {
   private:
      EstadoCrispr *inicial;
      EstadoCrispr *solucion; //el estado final
     

   public:
      ProblemaCrispr();
      ~ProblemaCrispr();
      Estado * getEstadoInicial(); 
      int esSolucion( Estado * ); 
      int heuristica(Estado *); 
      Lista * getSiguientes( Estado * );
      char mutar(char * a);

};
#endif