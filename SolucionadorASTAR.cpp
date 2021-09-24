#include "SolucionadorASTAR.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
#include <bits/stdc++.h>

using namespace std;

SolucionadorASTAR::SolucionadorASTAR(){
    profundidad = 0;
}

Solucion * SolucionadorASTAR::solucione( Problema * problema){
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
    profundidad = problema->heuristica(estado);
    bool resuelto = false;

}

Solucion * SolucionadorASTAR::solucioneRec(Problema * problema){

}
