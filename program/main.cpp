#include <iostream>
#include "grafo.h"
#include "grafo_ponderado.h"
#include "grafo_ponderado_dirigido.h"
#include "grafo_ponderado_negativo_dirigido.h"
int main() {
    Grafo grafo(3);
   // grafo.adiciona_aresta(0,1);
   // grafo.adiciona_aresta(1,2);
   // grafo.adiciona_aresta(0,2);
    grafo.imprime_grafo();
    std::cout<<"Teste !"<<std::endl;
    return 0;
}
