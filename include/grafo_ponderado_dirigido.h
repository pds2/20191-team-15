#ifndef GRAFO_PONDERADO_DIRIGIDO_H
#define GRAFO_PONDERADO_DIRIGIDO_H
#include "grafo_ponderado.h"

class GrafoPonderadoDirigido : public GrafoPonderado{

public:
    GrafoPonderadoDirigido(int num_vertices);
    void adiciona_aresta(int origem, int destino, int peso) override;
    GrafoPonderadoDirigido caminho_mais_curto(int origem, int destino);
    virtual int get_num_arestas() override;
    GrafoPonderadoDirigido menor_caminho(int origem, int destino);
};


#endif