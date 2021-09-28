#ifndef _ESTADO_TSP
#define _ESTADO_TSP

//#include "ProblemaEightPuzzle.h"
#include "Estado.h"

class EstadoTSP : public Estado {
   friend class ProblemaTSP;
  
  /*
  friend ostream& operator<<(ostream& salida, EstadoTSP & prueba){
       return prueba.imprimir(salida);
   }
  */

   private:
      
	int n; 

   public:
        int ** caminos;
       EstadoTSP();
      ~EstadoTSP();
      EstadoTSP * clonar();
      istream& cargar(istream&);
      ostream& imprimir(ostream&);
      int operator==(Estado *);
      int operator!=(Estado *);
      void pedirMemoria(int);
      void liberarMemoria();
      void crearCaminos();
      int getN();
};


#endif