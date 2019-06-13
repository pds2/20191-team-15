#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "aresta.h"
#include <iostream>



class Grafo{
private:
    int _num_vertices;
protected:
    std::vector<Aresta> *_vizinhos;
public:
    Grafo(int num_vertices);
    int get_num_vertices();
    bool existe_aresta(int v1, int v2);
    void adiciona_aresta(int v1, int v2);
    virtual int get_num_arestas();
    void imprime_grafo();
    std::vector<Aresta> get_adjacentes(int indice);
    bool eh_conexo();
    void busca_em_largura();

};

void busca_em_profundidade(Grafo *grafo, std::vector<int> &vertices, int inicio, int contador);

#endif