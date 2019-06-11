#include "aresta.h"

Aresta::Aresta(int v1, int v2, int peso){
        if(v1<0 || v2<0){
            throw ArestaInvalidaException();
        }
        else{
            _vertice1=v1;
            _vertice2=v2;
            _peso=peso;
        }
}


int Aresta::get_peso(){
    return _peso;
}

int Aresta::get_vertice1(){
    return _vertice1;
}

int Aresta::get_vertice2(){
    return _vertice2;
}

void Aresta::modifica_peso(int peso){
    _peso=peso;
}
