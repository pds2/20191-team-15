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

std::vector<int> GrafoPonderadoDirigido::menores_distancias(int origem){
    std::vector<int> distancias(this->get_num_vertices(),-1);
    std::vector<int> vertices_adicionados(this->get_num_vertices(),0);
    int atual=origem; //j
    distancias[origem]=0;
    vertices_adicionados[origem]=1;
    int num_vertices_adicionados=1;
    int v_menor_peso;
    int destino;
    while(num_vertices_adicionados<this->get_num_vertices()){
        for(unsigned int i=0;i<_vizinhos[atual].size();i++){
            destino=_vizinhos[atual][i].get_vertice2();
            if(distancias[destino]==-1){
                distancias[destino]=distancias[atual]+_vizinhos[atual][i].get_peso();
            }
            else if(distancias[destino]>distancias[atual]+_vizinhos[atual][i].get_peso()){
                distancias[destino]=distancias[atual]+_vizinhos[atual][i].get_peso();
            }
        }
        v_menor_peso=-1;
        for(int j=0;j<this->get_num_vertices();j++){
            if(vertices_adicionados[j]==0 && v_menor_peso==-1 && distancias[j]!=-1){
                v_menor_peso=j;
            }
            else if(vertices_adicionados[j]==0 && distancias[j]<distancias[v_menor_peso] && distancias[j]!=-1){
                v_menor_peso=j;
            }
        }
        /*
        if(v_menor_peso==-1){
            std::cout<<"ERRO!"<<std::endl;
            break;
        }
         */
        if(v_menor_peso!=-1){
            vertices_adicionados[v_menor_peso]=1;
            atual=v_menor_peso;
        }
        num_vertices_adicionados++;
    }
return distancias;
}
