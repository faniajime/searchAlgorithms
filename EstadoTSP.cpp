#include "EstadoTSP.h"
#include <random>
#include <time.h>
#include <algorithm>
#include <iostream>
using namespace std;

EstadoTSP::EstadoTSP()
{
    n = 5;
    pedirMemoria(n);
    crearCaminos();
}

EstadoTSP::~EstadoTSP()
{
    if (caminos)
    {
        liberarMemoria();
    }
}

EstadoTSP *EstadoTSP::clonar()
{
    EstadoTSP *nuevoEstado = new EstadoTSP();
    for (int f = 0; f < n; ++f)
    {
        for (int c = 0; c < n; ++c)
        {
            nuevoEstado->caminos[f][c] = this->caminos[f][c];
        }
    }
    return nuevoEstado;
}

istream &EstadoTSP::cargar(istream &entrada)
{
    for (int f = 0; f < n; ++f)
    {
        for (int c = 0; c < n; ++c)
        {
            entrada >> caminos[f][c];
        }
    }
    return entrada;
}

ostream &EstadoTSP::imprimir(ostream &salida)
{
    for (int f = 0; f < n; ++f)
    {
        for (int c = 0; c < n; ++c)
        {
            salida << caminos[f][c] << " ";
        }
        salida << endl;
    }
    salida << endl;
    return salida;
}

int EstadoTSP::operator==(Estado *otroEstado)
{
    EstadoTSP *estado = dynamic_cast<EstadoTSP *>(otroEstado);
    int esIgual = 1;

    for (int f = 0; f < n; ++f)
    {
        for (int c = 0; c < n; ++c)
        {
            if (this->caminos[f][c] != estado->caminos[f][c])
            {
                esIgual = 0;
                f = n;
                c = n;
            }
        }
    }
    return esIgual;
}

int EstadoTSP::operator!=(Estado *otroEstado)
{
    return !(*this == otroEstado);
}

void EstadoTSP::pedirMemoria(int tamanio)
{
    this->n = 0;
    this->caminos = 0;

    if (tamanio > 0)
    {
        this->n = tamanio;
        caminos = new int *[n];
        for (int i = 0; i < n; ++i)
        {
            caminos[i] = new int [n];
        }
    }
}

void EstadoTSP::liberarMemoria()
{
    for (int f = n - 1; f >= 0; --f)
    {
        delete[] caminos[f];
    }
    delete[] caminos;
    this->caminos = 0;
}


void EstadoTSP::crearCaminos()
{
    int rutas [] = {-2, 120, 220, 150, 210, 120, -1, 100, 110, 130, 220, 80, -1, 160, 185, 150, -1, 160, -1, 190, 210, 130, 185, -1, -1}; // tiene solucion
    //int rutas [] = {-2, 120, 220, 120, -1, 100, 220, 80, -1};3x3
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            caminos[i][j] = rutas[pos];
            pos++;
        }
    }
}

int EstadoTSP::getN()
{
    return this->n;
}