#include "SolucionadorIDA.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"

#include <bits/stdc++.h>

using namespace std;

SolucionadorIDA::SolucionadorIDA(){
    profundidad = 0;
    globalFound = 0;
}

Solucion * SolucionadorIDA::solucione( Problema * problema){
    start = std::chrono::steady_clock::now();
    bool timeDone = false;
    Estado* estado = problema->getEstadoInicial();
    NodoIDA * raiz = new NodoIDA();
    raiz->estado= estado;
    raiz->padre = NULL;
    raiz->nivel = 0;

    bool resuelto = false;
    int recorridos = 0;
    profundidad = fcost( problema, raiz->estado, 0);
    cout << "++++++++++++++ FINDING A SOLUTION WITH IDA +++++++++++++" <<endl;

    while(!resuelto && !timeDone){
        end = std::chrono::steady_clock::now();
        if((std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0) >  300){
            timeDone = true;
        }
        int res = buscar(raiz, problema);
        if(res == 1){
            resuelto = true;
            break;
        }else if(res == -1){
            cout << "here" << endl;
            cout << minHeuristica << endl;
            profundidad = minHeuristica;
            minHeuristica = 100000;
            //calcular nueva profundidad y vamos de nuevo
        }
        else if (res == -2){
            cout << "No se encontro solucion en el tiempo dado." << endl;
            return NULL;
        }
    }
    if(resuelto){
        return getSolucion(final);
    }else{
        cout << "No se encontro solucion en el tiempo dado" << endl;
        return NULL;
    }
    
    
}

int SolucionadorIDA::buscar(NodoIDA * nodo, Problema* problema) {
    //cout << "Mi estado:" << endl << nodo->estado << endl;
    //cout << "Mi nivel: " << nodo->nivel << endl;
    //cout << "Profundidad: " << nodo->nivel << endl;
    if(problema->esSolucion(nodo->estado)== 1 ){
        globalFound = 1;
        final = nodo;
        return 1;
    }else if( globalFound){
        return 1;
    }
    else if(nodo->nivel>=profundidad){
        int costo = fcost(problema, nodo->estado, nodo->nivel);
        if(costo< minHeuristica){
            minHeuristica = costo;            
        }
        return -1;
    }
    Lista * hijos = new Lista();
    hijos = problema->getSiguientes(nodo->estado);
    int temp= 0;
    Lista::Iterador i = hijos->begin();
    Lista::Iterador finish = hijos->end();
    for(i; i != finish; ++i)
    {
        NodoIDA * n = new NodoIDA();
        n->estado = *i;
        n->padre = nodo;
        n->nivel = nodo->nivel+1;
        int temp = buscar(n, problema);
        if(temp == 1){
            break;
        }
        end = std::chrono::steady_clock::now();
        if(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() >  120){
            return -2;
        }
    }
    return temp;
}

Solucion * SolucionadorIDA::getSolucion(NodoIDA * n){
    Lista * pasos = new Lista();
    cout << n->estado << endl;
    while(n->padre != NULL){
        pasos->push_front(n->estado);
        n = n->padre;
    }
    Solucion * s = new Solucion(pasos);
    return s;
}


int SolucionadorIDA::fcost(Problema * problema, Estado * estado, int nodos){
    int funcion = (nodos + problema->heuristica(estado));
    return funcion;
}
