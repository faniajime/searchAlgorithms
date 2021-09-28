#include "ProblemaCrispr.h"
#include<time.h>


using namespace std;

ProblemaCrispr::ProblemaCrispr(){
  srand(time(0));
  solucion = new EstadoCrispr(0);
  inicial = new EstadoCrispr(solucion->n);

  cout << "inicial state"<< endl; //QUITAR PARA COMPARAR CON LOS OTROS SOLUCIONADORES
  cout << inicial <<endl; //QUITAR PARA COMPARAR CON LOS OTROS SOLUCIONADORES

  
  cout << "desired solution"<< endl; //QUITAR PARA COMPARAR CON LOS OTROS SOLUCIONADORES
  cout << solucion <<endl; //QUITAR PARA COMPARAR CON LOS OTROS SOLUCIONADORES
  cout<<endl; //QUITAR PARA COMPARAR CON LOS OTROS SOLUCIONADORES

  cout << "Welcome to the crispr game" <<endl;
  cout << endl;
  cout << "   ***********************       * " << endl;
  cout << " **                       ***   **" << endl;
  cout << " **                       *** ** " << endl;
  cout << " **                       *** " << endl;
  cout << "   ******AATTAAAX********* " << endl;
  cout << endl;
  cout << endl;

}

ProblemaCrispr::~ProblemaCrispr() {

}

Estado * ProblemaCrispr::getEstadoInicial(){
   return this->inicial; 
}

int ProblemaCrispr::esSolucion( Estado * estadoAComparar){
    EstadoCrispr * est = dynamic_cast< EstadoCrispr * >(estadoAComparar);
    int esSolucion = 1;
    for(int i=0; i< solucion->n; i++){
      if(est->seq[i]!=solucion->seq[i]){
        esSolucion = 0;
        break;
      }
    }
    return esSolucion;
}

int ProblemaCrispr::heuristica(Estado * estado){
   EstadoCrispr * estadoActual = dynamic_cast< EstadoCrispr * >(estado);
   int heuristica = 0;

   for(int f = 0; f < estadoActual->n; ++f)
   {
    if(estadoActual->seq[f] !=solucion->seq[f])
        {
          heuristica++;
        } 
   }
   return heuristica;
}

Lista * ProblemaCrispr::getSiguientes( Estado * estado){
   EstadoCrispr * estadoC = dynamic_cast< EstadoCrispr * >(estado);
   Lista * siguientes = new Lista();
   int n = estadoC->n;
   bool eq = true;
   int it = 0;
   while(eq){
       if(estadoC->seq[it] != this->solucion->seq[it]){
           eq = false;
       }
       if(it == n){
         break;
       }
       it++;
   }
   

  if(estadoC){
    for(int i = 0; i< 4; i++){
        if(estadoC->seq[it] != estadoC->possibilities[i]){
            EstadoCrispr * clon1 = estadoC->clonar();
            clon1->seq[it] = clon1->possibilities[i];
            siguientes->push_back( clon1 );
            delete clon1;
        }
    }
  }
  return siguientes;
}      

