#include "SolucionadorASTAR.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
#include <bits/stdc++.h>

using namespace std;

SolucionadorASTAR::SolucionadorASTAR(){
    unexplored = new Lista();
    explored = new Lista();
}

Solucion* SolucionadorASTAR::solucione( Problema * problema)
{
    int resuelto = 0;
    int depth = 0;
    int cost;
    Lista* frontera = new Lista();
    Estado* estado = problema->getEstadoInicial();
    NodoA* raiz = new NodoA();
    raiz->estado = estado;
    raiz->padre = NULL;
    raiz->nivel = depth;
    explored->push_back(raiz->estado);   
    resuelto = problema->esSolucion(estado); 

    while(resuelto == 0) //|| !unexplored->isEmpty())
    {      
        cost = 10000;  
        depth += 1;
        frontera = problema->getSiguientes(estado);
        //cout<<"Frontera "<<endl;
        //cout<<frontera<<endl;
        Lista::Iterador i = frontera->begin();
        Lista::Iterador end = frontera->end();
        for(i; i != end; ++i)
        {
            NodoA * nuevo = new NodoA();
            nuevo->estado = *i;
            nuevo->padre = raiz;// raiz?
            nuevo->nivel = depth;
            unexplored->push_back(nuevo->estado);           
        }

        Lista::Iterador j = unexplored->begin();
        Lista::Iterador unexploredEnd = unexplored->end();
        
        for(j;j!= unexploredEnd;++j)
        {
            if(cost>(calculateCost(problema->heuristica(*j),depth)))
            { 
                cost = calculateCost(problema->heuristica(*j),depth);
                estado = *j;
                explored->push_back(unexplored->pop_front());
            }
        }
        //explored->push_back(estado);
        //cout<<"Estado: "<<endl;
        //cout<<estado<<endl;
        
        if(problema->heuristica(estado)==0)
        {
            resuelto = 1;
        }
    }
    solucion = retornarSolucion();
    return solucion;
}

/*
Calcular profundidad

*/
int SolucionadorASTAR :: calculateCost(int heuristic,int depth)
{
    return heuristic + depth;
}

Solucion * SolucionadorASTAR::retornarSolucion(){
  solucion = new Solucion(explored);
  return solucion;
}
/*
Solucion * SolucionadorASTAR::solucioneRec(Problema * problema){

}*/
