#include <iostream>
#include "grafo.h"
#include "grafo_ponderado.h"
#include "grafo_ponderado_dirigido.h"
#include "grafo_ponderado_negativo_dirigido.h"
#include "opcoes.h"


int main() {

    int opcao,opcao2;
    std::cout<<std::endl<<std::endl;
    std::cout<<"Digite a opcao de acordo com o time de grafo que voce deseja trabalhar: "<<std::endl;
    std::cout<<"Grafo nao ponderado - 1"<<std::endl;
    std::cout<<"Grafo ponderado - 2"<<std::endl;
    std::cout<<"Digite qualquer outro numero para encerrar o programa"<<std::endl;
    std::cout<<std::endl<<std::endl;
    std::cin >> opcao;
    if(opcao==1){
        opcao_grafo();
    }
    else if(opcao==2){
        std::cout<<"Voce deseja trabalhar com arestas dirigidas?"<<std::endl;
        std::cout<<"Sim - 1"<<std::endl;
        std::cout<<"Nao - 2"<<std::endl;

        std::cout<<"Digite qualquer outro numero para encerrar o programa"<<std::endl;
        std::cin>>opcao2;
        if(opcao2==1){
            opcao_grafo_ponderado_dirigido();
        }
        else if(opcao2==2){
            opcao_grafo_ponderado();
        }
    }
    else{
        std::cout<<"Opcao invalida - Programa encerrado"<<std::endl;
    }

    return 0;
}
