#ifndef TSP_FACTORY
#define TSP_FACTORY
#include "Fabrica.h"
#include "ProblemaTSP.h"

class TSPFactory : public Fabrica {
    public:
       ProblemaTSP * producir();
};

#endif
