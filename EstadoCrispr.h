#ifndef ESTADO_CRISPR
#define ESTADO_CRISPR

//#include "ProblemaEightPuzzle.h"
#include "Estado.h"

class EstadoCrispr : public Estado {
   friend class ProblemaCrispr;
  
  /*
  friend ostream& operator<<(ostream& salida, EstadoEightPuzzle & prueba){
       return prueba.imprimir(salida);
   }
  */

   public:
      int n;
      char* seq;
      char possibilities[4] = {'A', 'G', 'C', 'T'};
      EstadoCrispr(int len);
      ~EstadoCrispr();
      EstadoCrispr * clonar();
      istream& cargar(istream&);
      ostream& imprimir(ostream&);
      int operator==(Estado *);
      int operator!=(Estado *);
      void pedirMemoria(int);
      void liberarMemoria();
      void llenar();
};

#endif