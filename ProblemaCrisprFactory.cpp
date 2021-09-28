

#include "ProblemaCrisprFactory.h"

/**
 * Método producir crea problemas de tipo Problem051
 * @return retorna un puntero a un problema Problem051
 */
 ProblemaCrispr * ProblemaCrisprFactory::producir(){
   return new ProblemaCrispr();  
 }