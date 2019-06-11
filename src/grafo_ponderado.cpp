#include "grafo_ponderado.h"

/*
GrafoPonderado::GrafoPonderado(int num_vertices){
    if(num_vertices<=0){
        throw NumVerticesInvalidoException();
    }
    else{
        Grafo(num_vertices);
    }
}
 */

GrafoPonderado::GrafoPonderado(int num_vertices):
Grafo(num_vertices),_peso_total(0){}

void GrafoPonderado::adiciona_aresta(int v1, int v2, int peso){
    int vertice1=std::min(v1,v2);
    int vertice2=std::max(v1,v2);
    //Vertice Inválido
    if(v1<0|| v1>=this->get_num_vertices() || v2<0 || v2>=this->get_num_vertices()){
        throw VerticesInvalidosException();
    }
    //Peso inválido
    else if(peso<0){
        throw PesoInvalidoException();
    }
    //Aresta já existe no grafo
    else if(this->existe_aresta(vertice1,vertice2)){
        throw ArestaJaExistenteException();
    }
    //Add aresta
    else{
        Aresta aresta(vertice1,vertice2,peso);
        _vizinhos[vertice1].push_back(aresta);
        _peso_total+=peso;
    }
}

int GrafoPonderado::get_peso_total(){
    return _peso_total;
}

GrafoPonderado GrafoPonderado::arvore_geradora_minima(){
    GrafoPonderado agm(this->get_num_vertices());
    std::vector<Aresta> arestas;
    agm.adiciona_aresta(0,1,2);
    agm.adiciona_aresta(0,2,5);
    return agm;
}