#include "ProblemaTSP.h"

using namespace std;

ProblemaTSP::ProblemaTSP()
{
  inicial = new EstadoTSP();
  this->distancia = 0;
 
}

ProblemaTSP::~ProblemaTSP()
{
}

Estado *ProblemaTSP::getEstadoInicial()
{
  return this->inicial;
}

int ProblemaTSP::esSolucion(Estado *estadoAComparar)
{
  EstadoTSP *estado = dynamic_cast<EstadoTSP *>(estadoAComparar);
  int esSolucion = 1;
  int sumaCamino = 0;

  for (int f = 0; f < estado->getN(); ++f)
  {
    for (int c = 0; c < estado->getN(); ++c)
    {
      /*if (estado->caminos[f][c] == 0)
      {
        ciudadesVisitadas++;
      }*/
      sumaCamino += estado->caminos[f][c];
      cout<<"Suma de camino= "<<sumaCamino<<endl;
    }
    if(sumaCamino!= -1*(estado->getN()-1))
    {
      esSolucion = 0;
    }
    sumaCamino = 0;
  }
  /*if (ciudadesVisitadas >= (estado->getN() - 1))
  {
    esSolucion = 1;
  }*/
  return esSolucion;
}

int ProblemaTSP::heuristica(Estado *estado)
{
  EstadoTSP *estadoActual = dynamic_cast<EstadoTSP *>(estado);
  int heuristica = 0;
  int fila,columna;

  for (int f = 0; f < 3; ++f)
  {
    for (int c = 0; c < 3; ++c)
    {
      if (estadoActual->caminos[f][c] == -2)
      {
        fila = f;
        columna =c;
      }
    }
  }
  heuristica = inicial->caminos[fila][columna];
  return heuristica;
}

Lista * ProblemaTSP::getSiguientes(Estado *estado)
{
  EstadoTSP *estadoC = dynamic_cast<EstadoTSP *>(estado);
  Lista *siguientes = new Lista();
  int n = estadoC->n;
  int fila;
  int columna;

  for (int f = 0; f < n; ++f)
  {
    for (int c = 0; c < n; ++c)
    {
      if (estadoC->caminos[f][c] == -2)
      {
        fila = f;
        columna = c;
      }
    }
  }

  int tempFila;
  int tempColumna;
  if (estadoC)
  {
    //ciudad 1
    EstadoTSP *clon1 = estadoC->clonar();
    tempFila = fila;
    tempColumna = 0;

    if (estadoC->caminos[fila][tempColumna] > 0)
    {
      int index = estadoC->caminos[fila][tempColumna];
      //cout<<"soy mayor a 0 = "<<index<<endl;
      clon1->caminos[fila][columna] = 0;
      clon1->caminos[columna][tempColumna] = -2;
      for (int f= 0; f < n; ++f)
      {
        if(f!=fila)
        {
          clon1->caminos[f][columna] = -1;
          clon1->caminos[f][tempColumna] = -1;
        }
      }
      siguientes->push_back(clon1);
    }
    //cout<<"Clon 1"<<endl;
    //cout<<fila<<","<<columna<<","<<tempColumna<<endl;
    //cout<<clon1<<endl;
    delete clon1;

    //ciudad 2
    EstadoTSP *clon2 = estadoC->clonar();
    tempFila = fila;
    tempColumna = 1;

    if (estadoC->caminos[fila][tempColumna] > 0)
    {
      int index = estadoC->caminos[fila][tempColumna];
      //cout<<"soy mayor a 0 = "<<index<<endl;
      clon2->caminos[fila][columna] = 0;
      clon2->caminos[columna][tempColumna] = -2;
      for (int f= 0; f < n; ++f)
      {
        if(f!=fila)
        {
          clon2->caminos[f][tempColumna] = -1;
          clon2->caminos[f][columna] = -1;
        }
      }
      siguientes->push_back(clon2);
    }
    //cout<<"Clon 2"<<endl;
    //cout<<clon2<<endl;
    delete clon2;

   //ciudad 3
    EstadoTSP *clon3 = estadoC->clonar();
    tempFila = fila;
    tempColumna = 2;

    if (estadoC->caminos[fila][tempColumna] > 0)
    {
      clon3->caminos[fila][columna] = 0;
      clon3->caminos[columna][tempColumna] = -2;
      for (int f= 0; f < n; ++f)
      {
        if(f!=fila)
        {
          clon3->caminos[f][tempColumna] = -1;
          clon3->caminos[f][columna] = -1;
        }
      }
      siguientes->push_back(clon3);
    }
    //cout<<"Clon 3"<<endl;
    //cout<<clon3<<endl;
    delete clon3;
    /*
   //ciudad 4
    EstadoTSP *clon4 = estadoC->clonar();
    tempFila = fila;
    tempColumna = 3;

    if (estadoC->caminos[fila][tempColumna] > 0)
    {
      clon4->caminos[fila][columna] = 0;
      clon4->caminos[columna][tempColumna] = -2;
      for (int f= 0; f < n; ++f)
      {
        if(f!=fila)
        {
          clon4->caminos[f][tempColumna] = -1;
        }
      }
      siguientes->push_back(clon4);
    }
    //cout<<"Clon 4"<<endl;
    //cout<<clon4<<endl;
    delete clon4;

  //ciudad 5
    EstadoTSP *clon5 = estadoC->clonar();
    tempFila = fila;
    tempColumna = 4;

    if (estadoC->caminos[fila][tempColumna] > 0)
    {
      clon5->caminos[fila][columna] = 0;
      clon5->caminos[columna][tempColumna] = -2;
      for (int f= 0; f < n; ++f)
      {
        if(f!=fila)
        {
          clon5->caminos[f][tempColumna] = -1;
        }
      }
      siguientes->push_back(clon5);
    }
    //cout<<"Clon 5"<<endl;
    //cout<<clon5<<endl;
    delete clon5;*/
  }

  return siguientes;
}
