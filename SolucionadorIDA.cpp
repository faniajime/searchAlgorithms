#include "SolucionadorIDA.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
#include <bits/stdc++.h>

using namespace std;

SolucionadorIDA::SolucionadorIDA(){
    height = 0;
    maxProfundidad = 1;
}

Solucion * SolucionadorIDA::solucione( Problema * problema){
    Lista * pasos = new Lista();
    Estado* estado = problema->getEstadoInicial();

    Nodo * raiz = new Nodo();
    raiz->estado= estado;
    raiz->padre = NULL;

    int profundidad = 0;
    bool resuelto = false;
    int nodosVisitados = 0;

    maxProfundidad = fcost( problema, raiz->estado, nodosVisitados);

    while(fcost < 100 || !resuelto){
        int res = buscar(raiz, problema, profundidad);
        if(res == 1){
            //final, como encuentro el camino?
        }else if(res == -1){
            //calcular nueva profundidad y vamos de nuevo
        }

    }


}

int SolucionadorIDA::buscar(Nodo * nodo, Problema* problema, int profundidad)) {
    if(problema->esSolucion(nodo->estado)){
        return 1;
    }else if(profundidad>maxProfundidad){
        return -1;
    }
    if (nodo != NULL) {
        Lista * hijos = new Lista();
        profundidad+=1;
        hijos = problema->getSiguientes(nodo->estado);
        while(!hijos->isEmpty()){
            buscar(hijos.pop_front(), problema, profundidad);
        }
    }
}

Solucion * SolucionadorIDA::getSolucion(Nodo * n){
    Lista * pasos = new Lista();
    while(n->padre != NULL){
        pasos.push_front(n->estado);
        n = n->padre;
    }
    Solucion * s = new Solucion(pasos);
}


int SolucionadorIDA::fcost(Problema * problema, Estado * estado, int profundidad){
    int funcion = profundidad + problema->heuristica(estado);
    return funcion;

}