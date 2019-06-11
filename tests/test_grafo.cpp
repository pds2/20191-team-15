#include "doctest.h"
#include "grafo.h"

TEST_CASE("0 - Teste de construtor"){
    CHECK_THROWS(Grafo grafo(-1));
    CHECK_NOTHROW(Grafo grafo(4));
}


TEST_CASE("1 - Testando adicao de arestas"){
    Grafo grafo(3);
    grafo.adiciona_aresta(0,1);
    grafo.adiciona_aresta(1,2);
    CHECK(grafo.get_num_arestas()==2);
}

TEST_CASE("2 - Testando adicao de arestas invalidas"){
    Grafo grafo(4);
    CHECK_THROWS(grafo.adiciona_aresta(0,5));
    CHECK_THROWS(grafo.adiciona_aresta(0,-1));
    CHECK_THROWS(grafo.adiciona_aresta(8,1));
    CHECK_THROWS(grafo.adiciona_aresta(-5,3));
    CHECK(grafo.get_num_arestas()==0);
}

TEST_CASE("3 - Testando adicao de arestas ja existentes"){
    Grafo grafo(4);
    CHECK_NOTHROW(grafo.adiciona_aresta(0,1));
    CHECK_NOTHROW(grafo.adiciona_aresta(0,2));
    CHECK_THROWS(grafo.adiciona_aresta(0,1));
    CHECK_THROWS(grafo.adiciona_aresta(1,0));
    CHECK(grafo.get_num_arestas()==2);
}