#ifndef SOLUCIONADOR_ASTAR
#define SOLUCIONADOR_ASTAR
#include "Solucionador.h"
#include <list>

using namespace std;

class NodoA {
public:
    Estado * estado;
    NodoA * padre;
    int nivel;
};

class SolucionadorASTAR : public Solucionador {
   private:
      Lista * unexplored; 
      Lista * explored; 
      Lista * steps;
      //list <NodoA*> frontera;
      Solucion * solucion; 


   public:
      SolucionadorASTAR();
      Solucion * solucione(Problema *);
      /*Lista * revertPasos();
      void revertirSolucion(Nodo * final);
      void asignarPadre(Nodo* padre);
      void agregarAFrontera(Lista * siguientes); 
      int comprobarSiSolucion(Problema * problema); 
      void expandir(Problema* problema); */
      int calculateCost(int,int);
      Solucion * retornarSolucion();
};

#endif