#include "opcoes.h"

void opcao_grafo(){
    int opcao,num_vertices,num_arestas,v1,v2;
    std::cout<<"Quantos vertices seu grafo possui?"<<std::endl;
    std::cin>>num_vertices;
    Grafo grafo(num_vertices);
    inicio:
    std::cout<<std::endl<<"//////////////////////////////////////////////////////////////////"<<std::endl<<std::endl;
    std::cout<<"O que voce deseja fazer?"<<std::endl;
    std::cout<<"Adicionar arestas ao grafo - 1"<<std::endl;
    std::cout<<"Imprimir o grafo - 2"<<std::endl;
    std::cout<<"Verificar se o grafo e conexo - 3"<<std::endl;
    std::cout<<"Digite qualquer outro numero para encerrar o programa"<<std::endl;

    std::cin>>opcao;

    std::cout<<std::endl<<"//////////////////////////////////////////////////////////////////"<<std::endl<<std::endl;
    switch(opcao){
        case 1:
            std::cout<<"Quantas arestas deseja adicionar?"<<std::endl;
            std::cin>>num_arestas;
            for(int i=0;i<num_arestas;i++){
                std::cout<<"digite os vertices da arestas."<<std::endl;
                std::cout<<"Vertice 1: ";
                std::cin>>v1;
                std::cout<<"Vertice 2: ";
                std::cin>>v2;
                grafo.adiciona_aresta(v1,v2);
            }
            goto inicio;
        case 2:
            grafo.imprime_grafo();
            goto inicio;
        case 3:
            if(grafo.eh_conexo()){
                std::cout<<"O grafo e conexo."<<std::endl;
            }
            else{
                std::cout<<"O grafo nao e conexo."<<std::endl;
            }
            goto inicio;
        default:
            std::cout<<"encerrando o programa."<<std::endl;

    }
}

void opcao_grafo_ponderado(){
    int opcao,num_vertices,num_arestas,v1,v2,peso;
    std::cout<<"Quantos vertices seu grafo possui?"<<std::endl;
    std::cin>>num_vertices;
    GrafoPonderado grafo(num_vertices);
    inicio:
    GrafoPonderado agm=grafo.arvore_geradora_minima();
    std::cout<<std::endl<<"//////////////////////////////////////////////////////////////////"<<std::endl<<std::endl;
    std::cout<<"O que voce deseja fazer?"<<std::endl;
    std::cout<<"Adicionar arestas ao grafo - 1"<<std::endl;
    std::cout<<"Imprimir o grafo - 2"<<std::endl;
    std::cout<<"Verificar se o grafo e conexo - 3"<<std::endl;
    std::cout<<"Imprimir a arvore geradora minima do grafo - 4"<<std::endl;
    std::cout<<"Digite qualquer outro numero para encerrar o programa"<<std::endl;
    std::cin>>opcao;
    std::cout<<std::endl<<"//////////////////////////////////////////////////////////////////"<<std::endl<<std::endl;
    switch(opcao){
        case 1:
            std::cout<<"Quantas arestas deseja adicionar?"<<std::endl;
            std::cin>>num_arestas;
            for(int i=0;i<num_arestas;i++){
                std::cout<<"digite os vertices e o peso da aresta."<<std::endl;
                std::cout<<"Vertice 1: ";
                std::cin>>v1;
                std::cout<<"Vertice 2: ";
                std::cin>>v2;
                std::cout<<"Peso: ";
                std::cin>>peso;
                grafo.adiciona_aresta(v1,v2,peso);
            }
            goto inicio;
        case 2:
            grafo.imprime_grafo();
            goto inicio;
        case 3:
            if(grafo.eh_conexo()){
                std::cout<<"O grafo e conexo."<<std::endl;
            }
            else{
                std::cout<<"O grafo nao e conexo."<<std::endl;
            }
            goto inicio;
        case 4:
           // GrafoPonderado *agm = new grafo.arvore_geradora_minima();
            agm.imprime_grafo();
            goto inicio;
        default:
            std::cout<<"encerrando o programa."<<std::endl;

    }
}
void opcao_grafo_ponderado_dirigido(){
    int opcao,num_vertices,num_arestas,v1,v2,peso,origem;
    std::cout<<"Quantos vertices seu grafo possui?"<<std::endl;
    std::cin>>num_vertices;
    GrafoPonderadoDirigido grafo(num_vertices);
    std::vector<int> menores_distancias;
    inicio:
    std::cout<<std::endl<<"//////////////////////////////////////////////////////////////////"<<std::endl<<std::endl;
    std::cout<<"O que voce deseja fazer?"<<std::endl;
    std::cout<<"Adicionar arestas ao grafo - 1"<<std::endl;
    std::cout<<"Imprimir o grafo - 2"<<std::endl;
    std::cout<<"Verificar se o grafo e conexo - 3"<<std::endl;
    std::cout<<"Verificar as menores distancias a partir de um vertice - 4"<<std::endl;
    std::cout<<"Digite qualquer outro numero para encerrar o programa"<<std::endl;
    std::cin>>opcao;
    std::cout<<std::endl<<"//////////////////////////////////////////////////////////////////"<<std::endl<<std::endl;
    switch(opcao){
        case 1:
            std::cout<<"Quantas arestas deseja adicionar?"<<std::endl;
            std::cin>>num_arestas;
            for(int i=0;i<num_arestas;i++){
                std::cout<<"digite os vertices e o peso da aresta."<<std::endl;
                std::cout<<"Vertice 1: ";
                std::cin>>v1;
                std::cout<<"Vertice 2: ";
                std::cin>>v2;
                std::cout<<"Peso: ";
                std::cin>>peso;
                grafo.adiciona_aresta(v1,v2,peso);
            }
            goto inicio;
        case 2:
            grafo.imprime_grafo();
            goto inicio;
        case 3:
            if(grafo.eh_conexo()){
                std::cout<<"O grafo e conexo."<<std::endl;
            }
            else{
                std::cout<<"O grafo nao e conexo."<<std::endl;
            }
            goto inicio;
        case 4:
            std::cout<<"Digite o vertice de origem."<<std::endl;
            std::cout<<"Origem: ";
            std::cin>>origem;
            menores_distancias=grafo.menores_distancias(origem);
            std::cout<<std::endl<<"//////////////////////////////////////////////////////////////////"<<std::endl<<std::endl;
            for(unsigned int j=0;j<menores_distancias.size();j++){
                if(menores_distancias[j]!=-1){
                    std::cout<<"A distancia de "<<origem<<" ate "<<j<<" tem peso total "<<menores_distancias[j]<<std::endl;
                }
                else{
                    std::cout<<"Nao existe caminho de "<<origem<<" ate "<<j<<std::endl;
                }

            }
            goto inicio;
        default:
            std::cout<<"encerrando o programa."<<std::endl;

    }
}
void opcao_grafo_ponderado_negativo_dirigido(){

}
