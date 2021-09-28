#include "TSPFactory.h"
#include "ProblemaTSP.h"

ProblemaTSP * TSPFactory::producir(){
   return new ProblemaTSP();
}
