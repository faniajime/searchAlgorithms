
#ifndef _PROBLEM06051_FACTORY
#define _PROBLEM06051_FACTORY

#define NOMBRE_MAX_SIZE 100

#include "Fabrica.h"
#include "NazaProblem.h"
#include "Producto.h"
#include<cstring>

class NazaProblemFactory : public Fabrica{
   public:
      NazaProblem * producir(); 
      
};
       
#endif
