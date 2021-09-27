#ifndef SOLUCIONADOR_ASTAR_FACTORY
#define SOLUCIONADOR_ASTAR_FACTORY

#include "Fabrica.h"
#include "SolucionadorASTAR.h"

class SolucionadorASTARFactory : public Fabrica {
    public:
       SolucionadorASTAR * producir();
};

#endif


