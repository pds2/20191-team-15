#ifndef ARESTA_H
#define ARESTA_H
#include "excecoes.h"

class Aresta{
private:
    int _vertice1;
    int _vertice2;
    int _peso;
public:
    Aresta(int v1, int v2, int peso);
    int get_peso();
    int get_vertice1();
    int get_vertice2();
    void modifica_peso(int peso);
};

#endif