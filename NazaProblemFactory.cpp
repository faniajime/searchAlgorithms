
#include "NazaProblemFactory.h"

/**
 * Método producir crea problemas de tipo NazaProblem
 * @return retorna un puntero a un problema NazaProblem
 */
 NazaProblem * NazaProblemFactory::producir(){
   return new NazaProblem();  
 }