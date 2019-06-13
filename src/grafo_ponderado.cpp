#include "grafo_ponderado.h"

GrafoPonderado::GrafoPonderado(int num_vertices):
Grafo(num_vertices),_peso_total(0){}

void GrafoPonderado::adiciona_aresta(int v1, int v2, int peso){
    //Vertice Inválido
    if(v1<0|| v1>=this->get_num_vertices() || v2<0 || v2>=this->get_num_vertices()){
        throw VerticesInvalidosException();
    }
    //Peso inválido
    else if(peso<0){
        throw PesoInvalidoException();
    }
    //Aresta já existe no grafo
    else if(this->existe_aresta(v1,v2)){
        throw ArestaJaExistenteException();
    }
    //Add aresta
    else{
        Aresta aresta(v1,v2,peso);
        _vizinhos[v1].push_back(aresta);
        Aresta aresta2(v2,v1,peso);
        _vizinhos[v2].push_back(aresta2);
        _peso_total+=peso;
    }
}

int GrafoPonderado::get_peso_total(){
    return _peso_total;
}

GrafoPonderado GrafoPonderado::arvore_geradora_minima(){
    GrafoPonderado agm(this->get_num_vertices());
    std::vector<Aresta> vetor_arestas;
    std::vector<int> vertices_adicionados(this->get_num_vertices(),0);
    for(int i=0;i<this->get_num_vertices();i++){
        for(unsigned int j=0;j<_vizinhos[i].size();j++){
            vetor_arestas.push_back(_vizinhos[i][j]);
        }
    }
    //Se o grafo não for conexo ele não possui agm.
    if(this->eh_conexo()){
        int v1,v2,peso;
        //inicializa a construção da agm pelo vertice 0.
        std::sort(vetor_arestas.begin(),vetor_arestas.end(),compara_arestas);
        v1=vetor_arestas[0].get_vertice1();
        v2=vetor_arestas[0].get_vertice2();
        peso=vetor_arestas[0].get_peso();
        agm.adiciona_aresta(v1,v2,peso);
        vertices_adicionados[v1]=1;
        vertices_adicionados[v2]=1;
        //A cada iteração adiciona a aresta com menor peso que liga um vertice na agm a um vertice fora da agm.
        for(int k=0;k<this->get_num_vertices()-1;k++){
            for(unsigned int l=0;l<vetor_arestas.size();l++){
                v1=vetor_arestas[l].get_vertice1();
                v2=vetor_arestas[l].get_vertice2();
                peso=vetor_arestas[l].get_peso();
                if(vertices_adicionados[v1]==1 && vertices_adicionados[v2]==0){
                    agm.adiciona_aresta(v1,v2,peso);
                    vertices_adicionados[v2]=1;
                    break;
                }
                else if(vertices_adicionados[v1]==0 && vertices_adicionados[v2]==1){
                    agm.adiciona_aresta(v1,v2,peso);
                    vertices_adicionados[v1]=1;
                    break;
                }
            }
        }
    }
    return agm;
}

void GrafoPonderado::imprime_grafo(){
    int i;
    unsigned int j;
    if(this->get_num_arestas()!=0){
        for(i=0;i<this->get_num_vertices();i++){
            for(j=0;j<_vizinhos[i].size();j++){
                std::cout<<"("<<i<<", "<<_vizinhos[i][j].get_vertice2()<<", "<<_vizinhos[i][j].get_peso()<<")"<<std::endl;
            }
        }
    }
    else{
        std::cout<<"Grafo sem arestas adicionadas!"<<std::endl;
    }
}