#include "grafo_ponderado_dirigido.h"

GrafoPonderadoDirigido::GrafoPonderadoDirigido(int num_vertices):
GrafoPonderado(num_vertices){}

void GrafoPonderadoDirigido::adiciona_aresta(int origem, int destino, int peso){
    if(origem<0|| origem>=this->get_num_vertices() || destino<0 || destino>=this->get_num_vertices()){
        throw VerticesInvalidosException();
    }
    //Peso inválido
    else if(peso<0){
        throw PesoInvalidoException();
    }
    //Aresta já existe no grafo
    else if(this->existe_aresta(origem,destino)){
        throw ArestaJaExistenteException();
    }
    //Add aresta
    else{
        Aresta aresta(origem,destino,peso);
        _vizinhos[origem].push_back(aresta);
        _peso_total+=peso;
    }
}

int GrafoPonderadoDirigido::get_num_arestas(){
    int i, num_arestas=0;
    for(i=0;i<this->get_num_vertices();i++){
        num_arestas+=_vizinhos[i].size();
    }
    return num_arestas;
}
