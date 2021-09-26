#include "SolucionadorASTAR.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
#include <bits/stdc++.h>

using namespace std;

SolucionadorASTAR::SolucionadorASTAR(){
    profundidad = 0;
   // fScore = 0;
    hScore = 0;
 //   gScore = 0;
}

Solucion * SolucionadorASTAR::solucione( Problema * problema){
    int visitedNodes = 0;
    Estado * estadoInicial;
    Estado * estadoSiguiente;
    Lista * Iterador iterador;
    Lista * unexplored = new Lista();
    Lista * explored = new Lista();

    Estado * estado = problema->getEstadoInicial();
    gScore = problema->heuristica(estado) + visitedNodes +1;
    estado->costo = gScore;
    estadoInicial = estado;
    unexplored.push_back(estadoInicial);
    while (!unexplored.isEmpty()) {
        // get state with lowest costo
        estado = unexplored.peek();
        Lista::Iterador costoMasBajo = unexplored.begin();
        for (iterador = unexplored.begin(); iterador !=end(); ++iter) {
            if (iterador->costo < estado->costo) {
                estado = *iterador;
                costoMasBajo = iterador;
            }
        }
        explored.push_back(estado);
        unexplored.borrar(costoMasBajo);

        if (problema->esSolucion(estado)) {
            break;
        }
        //implementar vecinos de estado
        for (auto& vecinos:estado.vecinos) {
            //simular proxima movida, implementar..
            problema->getSiguientes(vecinos);
            //revisar si vecino ya esta en explored
            bool yaExplorado = false;
            for (auto& estados: explored) {
                if (estadoSiguiente == estados) {
                    yaExplorado = true;
                    break;
                }
            }
            if (!yaExplorado) {
                Estado * tempEstado = NULL;
                for (auto& estados: unexplored) {
                    if (estadoSiguiente == estados) {
                        tempEstado =&estados;
                        break;
                    }
                }

                if (estadoSiguiente->costo < estado->costo || !tempEstado)
                {
                    iterador = --explored.end(); 
                    estadoSiguiente->padre = &*iterador;
                    // este costo de la heuristica se deberia vincular con el estado y se deberia poder actualizarse en tiempo real.. ahrotia solo calcula el inicial entocnes no funciona
                   hScore = problema->heuristica + visitedNodes;

                    if (!tempEstado)
                        unexplored.push_back(estadoSiguiente);
                    else {
                                         // este costo de la heuristica se deberia vincular con el estado y se deberia poder actualizarse en tiempo real.. ahrotia solo calcula el inicial entocnes no funciona
                        hScore = problema ->heuristica + visitedNodes;                    }

                    }
                }
            }
        }
        // retornarPasos() recursivo;
        // agregarPasos para imprimir

    }

        /*
    pseudocode
    costo = heuristica + profundidad
    unexplored = new lista nodos a ser evaluado a traversar 
    explored =new lista nodos ya traversados 
    
    loop
        nodo actual = nodo en unexplored con costo mas bajo
        pop nodo actual de unexplored
        add nodo actual a lista explored

        if nodo actual es estado meta
            return; (termina)

        while (i< cantidad de vecinos de nodo actual)
            if vecino no es traversable || vecino se encuentra en lista explorado
                i ++ (ir a proximo vecino)

            if nueva ruta a vecino es mas corto o vecino != nodo en open
                set costo de nodo vecino
                nodo actual = padre de nodo vecino
                if nodo vecino no está en lista unexplored
                    unexplored.push(vecino)ñ
    --end of loop

    */


    Estado* estado = problema->getEstadoInicial();
    profundidad = problema->heuristica(estado) + 
    bool resuelto = false;


}

