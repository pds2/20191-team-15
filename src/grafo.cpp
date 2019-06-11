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
    //int vertice1=std::min(v1,v2);
    //int vertice2=std::max(v1,v2);
    for(i=0;i<_vizinhos[v1].size();i++){
        if(_vizinhos[v1][i].get_vertice2()==v2){
            return true;
        }
    }
    return false;
}

void Grafo::adiciona_aresta(int v1, int v2){
    int vertice1=std::min(v1,v2);
    int vertice2=std::max(v1,v2);
    //Aresta inválida
    if(v1<0|| v1>=this->get_num_vertices() || v2<0 || v2>=this->get_num_vertices()){
        throw VerticesInvalidosException();
    }
    //Aresta já existe
    else if(this->existe_aresta(vertice1,vertice2)){
        throw ArestaJaExistenteException();
    }
    //Add aresta
    else{
        Aresta aresta(vertice1,vertice2,0);
        //Aresta aresta_volta(v2,v1,0);
        _vizinhos[vertice1].push_back(aresta);
        //_vizinhos[v2].push_back(aresta_volta);
    }
}

int Grafo::get_num_arestas(){
    int i, num_arestas=0;
    for(i=0;i<this->get_num_vertices();i++){
        num_arestas+=_vizinhos[i].size();
    }
    return num_arestas;
}

void Grafo::imprime_grafo(){
    int i,contador=0;
    unsigned int j;
    for(i=0;i<this->get_num_vertices();i++){
        for(j=0;j<_vizinhos[i].size();j++){
            contador++;
            std::cout<<"("<<i<<", "<<_vizinhos[i][j].get_vertice2()<<")"<<std::endl;
        }
    }
    if(contador==0){
        std::cout<<"Grafo sem arestas adicionadas"<<std::endl;
    }
}




bool Grafo::eh_conexo(){

return false;
}

void busca_em_profundidade(Grafo grafo, std::list<int> vertices, int inicio){

}