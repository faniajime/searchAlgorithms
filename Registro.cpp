#include "Registro.h"
#include "Fabrica.h"
// AGREGUE UNA FABRICA DE SOLUCIONADOR Y UNA DE PROBLEMA
// POR CADA MIEMBRO Z DE SU GRUPO XX EQUIPO YY
// MIEMBRO 0
#include "EightPuzzleFactory.h"
#include "SolucionadorAnchoPrimeroFactory.h"
#include "SolucionadorIDAFactory.h"
#include "SolucionadorASTARFactory.h"

// MIEMBRO Nazareth Rojas
#include "NazaProblemFactory.h"
// MIEMBRO Sung Jae Moon
#include "ProblemaSungJaeFactory.h"


void Registro::add(const char * nombre, Fabrica * fabrica){
   if(cantidad<CAPACIDAD){
      if(fabrica){
         fabrica->setNombre(nombre);
         this->fabrica[cantidad++] = fabrica;
      }
   }
}

Registro::Registro(){
   // AL INICIO HAY 0 FABRICAS INSCRITAS
   cantidad = 0;
   // SE CREAN INSTANCIAS DE FABRICA Y SE REGISTRAN

   // Registran los del miembro 1 del equipo YY del grupo XX

   //Problema base 8Puzzle
   this->add("8Puzzle", new EightPuzzleFactory() );

   // miembro Nazareth Rojas
   this->add("NazaP", new NazaProblemFactory() );

   // miembro Sung Jae
   this->add("SungJae", new ProblemaSungJaeFactory());

   // solucionador Base Ancho Primero
   this->add("SolucionadorAnchoPrimero", new SolucionadorAnchoPrimeroFactory() );

   // solucionador AStar
   this->add("SolucionadorASTAR", new SolucionadorASTARFactory());

   // solucionador IDAStar
   this->add("SolucionadorIDA", new SolucionadorIDAFactory() );
   
}

Registro::~Registro(){
   for(int i=0; i<cantidad; ++i){
      if(fabrica[i]){
         delete fabrica[i];
      }
   }
}

Fabrica * Registro::getFabrica(const char * nombre){
   Fabrica * fabricaPtr = 0;
   for(int i=0; !fabricaPtr && i<cantidad; ++i){
      if( this->fabrica[i]->produce( nombre ) ){
         fabricaPtr = this->fabrica[i];
      }
   }   
   return fabricaPtr;
}
