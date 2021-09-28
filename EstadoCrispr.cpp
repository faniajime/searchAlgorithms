#include "EstadoCrispr.h"
#include <random>
#include <time.h>
#include <algorithm>
#include <iostream>
using namespace std;

EstadoCrispr::EstadoCrispr(int len = 0){
  if(len==0){
    srand(time(0));
    n = rand() % 21 + 5 ;
  }else{
    n = len;
  }

  pedirMemoria(n);
  llenar();
}

EstadoCrispr::~EstadoCrispr(){
    liberarMemoria();

}

EstadoCrispr * EstadoCrispr::clonar(){
  EstadoCrispr * nuevoEstado= new EstadoCrispr();  
  for(int f=0; f < n; ++f){
    nuevoEstado->seq[f]= this->seq[f];
  }
  return nuevoEstado;
}

istream& EstadoCrispr::cargar(istream& entrada){
  for(int f = 0; f<n; ++f){
  	entrada >> seq[f];
  }
  return entrada;
}

ostream& EstadoCrispr::imprimir(ostream& salida){
  for(int f = 0; f < n; ++f){
  	salida << seq[f] << " ";
  }
  salida << endl;
  return salida;
}

int EstadoCrispr::operator==(Estado * otroEstado){
  EstadoCrispr * estado = dynamic_cast<EstadoCrispr *>(otroEstado);
  int esIgual = 1; 
  for(int f = 0; f < n; ++f){
    if (this->seq[f] != estado->seq[f]){
  		esIgual = 0;
  		break;
	}
  }
  return esIgual;
}

int EstadoCrispr::operator!=(Estado * otroEstado){
   return !(*this==otroEstado);
}

void EstadoCrispr::pedirMemoria(int tamanio){
    this->seq = new char[tamanio];
}

void EstadoCrispr::liberarMemoria(){
	delete[] this->seq;
}

void EstadoCrispr::llenar(){
  int randIndex = rand() % 4;
	for(int i = 0; i < n; i++){
        seq[i] = possibilities[randIndex];
        randIndex = rand() % 4;
    }
}

