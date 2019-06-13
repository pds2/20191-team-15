#ifndef GRAFO_PONDERADO_H
#define GRAFO_PONDERADO_H

#include <algorithm>
#include "grafo.h"

class GrafoPonderado : public Grafo{
protected:
    int _peso_total;
public:
    GrafoPonderado(int num_vertices);
    virtual void adiciona_aresta(int v1, int v2, int peso);
    int get_peso_total();
    GrafoPonderado arvore_geradora_minima();


};

#endif