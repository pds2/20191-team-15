#include "grafo.h"

Grafo::Grafo(int num_vertices){
    if(num_vertices<=0){
        throw NumVerticesInvalidoException();
    }
    else{
        _num_vertices=num_vertices;
        _vizinhos=new std::vector<Aresta>[num_vertices];
    }

}

int Grafo::get_num_vertices(){
    return _num_vertices;
}

bool Grafo::existe_aresta(int v1, int v2){
    unsigned int i;
    for(i=0;i<_vizinhos[v1].size();i++){
        if(_vizinhos[v1][i].get_vertice2()==v2){
            return true;
        }
    }
    return false;
}

void Grafo::adiciona_aresta(int v1, int v2){
    //Aresta inválida
    if(v1<0|| v1>=this->get_num_vertices() || v2<0 || v2>=this->get_num_vertices()){
        throw VerticesInvalidosException();
    }
    //Aresta já existe
    else if(this->existe_aresta(v1,v2)){
        throw ArestaJaExistenteException();
    }
    //Add aresta
    else{
        Aresta aresta(v1,v2,0);
        _vizinhos[v1].push_back(aresta);
        Aresta aresta2(v2,v1,0);
        _vizinhos[v2].push_back(aresta2);

    }
}

int Grafo::get_num_arestas(){
    int i, num_arestas=0;
    for(i=0;i<this->get_num_vertices();i++){
        num_arestas+=_vizinhos[i].size();
    }
    return num_arestas/2;
}

void Grafo::imprime_grafo(){
    int i;
    unsigned int j;
    if(this->get_num_arestas()!=0){
        for(i=0;i<this->get_num_vertices();i++){
            for(j=0;j<_vizinhos[i].size();j++){
                std::cout<<"("<<i<<", "<<_vizinhos[i][j].get_vertice2()<<")"<<std::endl;
            }
        }
    }
    else{
        std::cout<<"Grafo sem arestas adicionadas!"<<std::endl;
    }
}


bool Grafo::eh_conexo(){
    int contador=1;
    unsigned int i;
    std::vector<int> vertices(this->get_num_vertices(),0);
    busca_em_profundidade(this,vertices,0,contador);
    for(i=0;i<vertices.size();i++){
        if(vertices[i]==0){
            return false;
        }
    }
    return true;
}

std::vector<Aresta> Grafo::get_adjacentes(int indice){
    return _vizinhos[indice];
}

void busca_em_profundidade(Grafo *grafo, std::vector<int> &vertices, int inicio, int contador){
    unsigned int i;
    int proximo;
    vertices[inicio]=contador;
    for(i=0;i<grafo->get_adjacentes(inicio).size();i++){
        proximo=grafo->get_adjacentes(inicio)[i].get_vertice2();
        if(vertices[proximo]==0){
            busca_em_profundidade(grafo,vertices,proximo,contador+1);
        }
    }
}