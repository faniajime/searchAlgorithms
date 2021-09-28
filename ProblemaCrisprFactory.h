
#ifndef _PROBLEMACRISPR_FACTORY
#define _PROBLEMACRISPR_FACTORY


#include "Fabrica.h"
#include "ProblemaCrispr.h"
#include "Producto.h"
#include<cstring>

class ProblemaCrisprFactory : public Fabrica{
   public:
      ProblemaCrispr * producir(); 
      
};
       
#endif
