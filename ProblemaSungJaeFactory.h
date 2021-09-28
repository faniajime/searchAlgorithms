#ifndef PROBLEMA_SJM_FACTORY
#define PROBLEMA_SJM_FACTORY
#include "Fabrica.h"
#include "ProblemaSungJae.h"

class ProblemaSungJaeFactory : public Fabrica {

    public:
      
       ProblemaSungJae * producir();
};

#endif
