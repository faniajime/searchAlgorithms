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

    NodoIDA * raiz = new NodoIDA();
    raiz->estado= estado;
    raiz->padre = NULL;

    int profundidad = 0;
    bool resuelto = false;
    Solucion * s;
    Lista * solucion;
    maxProfundidad = fcost( problema, raiz->estado, profundidad);
    minHeuristica = 100000;

    while(maxProfundidad < 1000 || !resuelto){
        int res = buscar(raiz, problema, profundidad);
        if(res == 1){
            s = getSolucion(final);
            resuelto = true;
            //final,[] como encuentro el camino?
        }else if(res == -1){
            maxProfundidad = minHeuristica;
            profundidad = 0;
            minHeuristica =100000;
            //calcular nueva profundidad y vamos de nuevo
        }

    }
    if(s){
        return s;
    }else{
        s =new Solucion(solucion);
        return s;
    }
}

int SolucionadorIDA::buscar(NodoIDA * nodo, Problema* problema, int profundidad) {
    if(problema->esSolucion(nodo->estado)){
        final = nodo;
        return 1;
    }else if(profundidad>maxProfundidad){
        return -1;
    }
    else if(profundidad== maxProfundidad){
        int costo =fcost(problema, nodo->estado, profundidad);
        if(costo< minHeuristica){
            minHeuristica = costo;            
        }
    }
    if (nodo != NULL) {
        Lista * hijos = new Lista();
        profundidad+=1;
        hijos = problema->getSiguientes(nodo->estado);
        while(!(hijos->isEmpty())){
            NodoIDA * n = new NodoIDA();
            n->estado = hijos->pop_front();
            n->padre = nodo;
            buscar(n, problema, profundidad);
        }
    }
}

Solucion * SolucionadorIDA::getSolucion(NodoIDA * n){
    Lista * pasos = new Lista();
    while(n->padre != NULL){
        pasos->push_front(n->estado);
        n = n->padre;
    }
    Solucion * s = new Solucion(pasos);
}


int SolucionadorIDA::fcost(Problema * problema, Estado * estado, int profundidad){
    int funcion = profundidad + problema->heuristica(estado);
    return funcion;
}