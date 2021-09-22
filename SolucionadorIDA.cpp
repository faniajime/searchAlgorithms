#include "SolucionadorIDA.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
#include <bits/stdc++.h>

using namespace std;

SolucionadorIDA::SolucionadorIDA(){
    profundidad = 0;
    maxProfundidad=0;
}

Solucion * SolucionadorIDA::solucione( Problema * problema){
    Lista * pasos = new Lista();
    Lista * frontera = new Lista();
    Lista * visitados = new Lista();
    Estado* estado = problema->getEstadoInicial();

    profundidad = 0;
    bool resuelto = false;
    int nodosVisitados = 0;
    int fcost = fcost( problema, estado, nodosVisitados);


    if(problema->esSolucion(estado)){
        pasos.append(estado);
        Solucion * solucion = new Solucion(pasos);
        return solucion;
    }

    while(!resuelto){
        while(nodosVisitados < fcost){
            frontera->push_back(estado);
            if(frontera->isEmpty()){
                return nullptr;
            }
            estado = frontera->pop_front();
            ++nodosVisitados;
            visitados->push_back(estado);
            frontera->push_back(problema->getSiguientes(estado));
            while(!frontera->isEmpty()){
                Estado * estadoActual = frontera->pop_front();
                if(visitados->buscar(estadoActual) == nullptr){
                    if(problema->esSolucion(estadoActual)){
                        pasos->push_front(hijo);
                        return new Solucion(pasos);
                    }
                    frontera->push_back(estadoActual);
                }
            }
            Lista::Iterador j = frontera->begin();
            Lista::Iterador fin = frontera->end();
            problema->getSiguientes(*j);
        }
        
    }
}




int SolucionadorIDA::fcost(Problema * problema, Estado * estado, int nodos){
    
    int funcion = nodos + problema->heuristica(estado);
    return funcion;

}