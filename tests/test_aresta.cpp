#include "doctest.h"
#include "aresta.h"

TEST_CASE("0 - Criando aresta que ligam vertices invalidos"){
    CHECK_THROWS(Aresta aresta(-1,1,2));
    CHECK_THROWS(Aresta aresta(1,-1,3));
}

TEST_CASE("1 - Testando getters"){
    Aresta aresta(0,1,2);
    CHECK(aresta.get_vertice1()==0);
    CHECK(aresta.get_vertice2()==1);
    CHECK(aresta.get_peso()==2);
}

TEST_CASE("2 - modificacao no peso"){
    Aresta aresta(1,3,5);
    aresta.modifica_peso(2);
    CHECK(aresta.get_peso()==2);
}