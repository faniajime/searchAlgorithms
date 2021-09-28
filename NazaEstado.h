#ifndef _NAZA_ESTADO
#define _NAZA_ESTADO
#include <stdlib.h>
#include <time.h>
#include "Estado.h"

class NazaEstado : public Estado {
  friend class NazaProblem;

   private:
      char **m;
      int n;
      int rFila; 
      int rCol; 
      int murciFila; 
      int murciCol; 
	
   public:
      NazaEstado();
      NazaEstado(int); 
      NazaEstado * clonar();
      ~NazaEstado();
      istream& cargar(istream&);
      ostream& imprimir(ostream&);
      int operator==(Estado *);
      int operator!=(Estado *);

      void pedirMemoria(int);
      void liberarMemoria();
      void llenarVacia();
      int verificarVecinos(int, int);
      void ponerObstaculos();
      void ponerMurciRefugio();

};
#endif