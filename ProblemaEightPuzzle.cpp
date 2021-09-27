#include "ProblemaEightPuzzle.h"


using namespace std;

ProblemaEightPuzzle::ProblemaEightPuzzle(){
  inicial = new EstadoEightPuzzle();

cout << "inicial state"<< endl; //QUITAR PARA COMPARAR CON LOS OTROS SOLUCIONADORES
  cout << inicial <<endl; //QUITAR PARA COMPARAR CON LOS OTROS SOLUCIONADORES

  solucion = inicial->clonar();
  cout << "desired solution"<< endl; //QUITAR PARA COMPARAR CON LOS OTROS SOLUCIONADORES
  solucion->m[0][0] = '1';
  solucion->m[0][1] = '2';
  solucion->m[0][2] = '3';
  solucion->m[1][0] = '4';
  solucion->m[1][1] = '5';
  solucion->m[1][2] = '6';
  solucion->m[2][0] = '7';
  solucion->m[2][1] = '8';
  solucion->m[2][2] = '0';
  cout << solucion <<endl; //QUITAR PARA COMPARAR CON LOS OTROS SOLUCIONADORES
  cout<<endl; //QUITAR PARA COMPARAR CON LOS OTROS SOLUCIONADORES
}

ProblemaEightPuzzle::~ProblemaEightPuzzle() {

}

Estado * ProblemaEightPuzzle::getEstadoInicial(){
   return this->inicial; 
}

int ProblemaEightPuzzle::esSolucion( Estado * estadoAComparar){
    EstadoEightPuzzle * est = dynamic_cast< EstadoEightPuzzle * >(estadoAComparar);
    int esSolucion = 0;
    if(*solucion == est){
        esSolucion = 1;
    }
    return esSolucion;
}

int ProblemaEightPuzzle::heuristica(Estado * estado){
   EstadoEightPuzzle * estadoActual = dynamic_cast< EstadoEightPuzzle * >(estado);
   int heuristica = 0;
   int posicion = 0;

   for(int f = 0; f < 3; ++f)
   {
     for(int c = 0; c < 3; ++c)
     {
        if(estadoActual->m[f][c] !=solucion->m[f][c] && estadoActual->m[f][c] != '0')
        {
          heuristica++;
        } 
        /*heuristica += distanciaManhattan(posicion, estadoActual->m[f][c]);
       ++posicion;*/      
     }
   }
   return heuristica;
}

int ProblemaEightPuzzle::distanciaManhattan(int posicionActual, int valorAEvaluar){
  int filaActual = posicionActual / 3;
  int colActual = posicionActual % 3;

  int filaSolucion = (valorAEvaluar - 1) / 3;
  int colSolucion = (valorAEvaluar - 1) % 3;

  if((valorAEvaluar - 1) < 0){
    filaSolucion = 2;
    colSolucion = 2;
  }
  return ( (abs(filaSolucion - filaActual)) + (abs(colSolucion - colActual)));
}


Lista * ProblemaEightPuzzle::getSiguientes( Estado * estado){
   EstadoEightPuzzle * estadoC = dynamic_cast< EstadoEightPuzzle * >(estado);
   Lista * siguientes = new Lista();
  int n = estadoC->n;
  int fila;
  int columna;

  for(int f = 0; f < n; ++f){
    for(int c = 0; c < n; ++c){
      if (estadoC->m[f][c] == '0'){
        fila = f;
        columna = c;
      }
    }
  }

  int tempfila;
  int tempcolumna;
  if(estadoC){
    //arriba  (f-1)
    EstadoEightPuzzle * clon1 = estadoC->clonar();
    int tempfila = fila-1;
    if(tempfila >= 0){
        clon1->m[fila][columna] = estadoC->m[tempfila][columna];
        clon1->m[tempfila][columna] = '0';
        siguientes->push_back( clon1 );
    }
    delete clon1;
    
    //abajo (f+1)
    EstadoEightPuzzle * clon2 = estadoC->clonar();
    tempfila = fila+1;
    if(tempfila <= 2){
      clon2->m[fila][columna] = estadoC->m[tempfila][columna];
      clon2->m[tempfila][columna] = '0';
      siguientes->push_back( clon2 );
    }
    delete clon2; 
    
    //izq (c-1)
    EstadoEightPuzzle * clon3 = estadoC->clonar();
    tempcolumna = columna -1;
    if(tempcolumna >= 0){
      clon3->m[fila][columna] = estadoC->m[fila][tempcolumna];
      clon3->m[fila][tempcolumna] = '0';
      siguientes->push_back( clon3 );
    }
    delete clon3;
    
    //derecha (c+1)
    EstadoEightPuzzle * clon4 = estadoC->clonar();
    tempcolumna = columna+1;
    if(tempcolumna <= 2){
      clon4->m[fila][columna] = estadoC->m[fila][tempcolumna];
      clon4->m[fila][tempcolumna] = '0';
        siguientes->push_back( clon4 );
    } 
    delete clon4;
  }
  
  return siguientes;
}      

