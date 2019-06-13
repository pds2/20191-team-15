#include "doctest.h"
#include "grafo.h"

TEST_CASE("0 - Teste de construtor"){
    CHECK_THROWS(Grafo grafo1(-1));
    CHECK_NOTHROW(Grafo grafo2(4));
}


TEST_CASE("1 - Testando adicao de arestas"){
    Grafo grafo(3);
    grafo.adiciona_aresta(0,1);
    grafo.adiciona_aresta(1,2);
    CHECK(grafo.get_num_vertices()==3);
    CHECK(grafo.existe_aresta(0,1)==true);
    CHECK(grafo.existe_aresta(0,2)==false);
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

TEST_CASE("4 - Testando se um grafo e conexo"){
    Grafo grafo(8);
    CHECK_NOTHROW(grafo.adiciona_aresta(0,1));
    CHECK_NOTHROW(grafo.adiciona_aresta(0,2));
    CHECK_NOTHROW(grafo.adiciona_aresta(0,3));
    CHECK_NOTHROW(grafo.adiciona_aresta(2,4));
    CHECK_NOTHROW(grafo.adiciona_aresta(3,6));
    CHECK_NOTHROW(grafo.adiciona_aresta(3,5));
    CHECK_NOTHROW(grafo.adiciona_aresta(5,7));
    CHECK(grafo.eh_conexo()==true);
}

TEST_CASE("5 - Testando se um grafo nao e conexo"){
    Grafo grafo(8);
    CHECK_NOTHROW(grafo.adiciona_aresta(0,1));
    CHECK_NOTHROW(grafo.adiciona_aresta(0,2));
    CHECK_NOTHROW(grafo.adiciona_aresta(0,3));
    CHECK_NOTHROW(grafo.adiciona_aresta(2,4));
    CHECK_NOTHROW(grafo.adiciona_aresta(3,6));
    CHECK_NOTHROW(grafo.adiciona_aresta(3,4));
    CHECK_NOTHROW(grafo.adiciona_aresta(5,7));
    CHECK(grafo.eh_conexo()==false);
}

TEST_CASE("6 - Testando a impressao do grafo"){
    Grafo grafo(3);
    grafo.imprime_grafo();
    CHECK_NOTHROW(grafo.adiciona_aresta(0,1));
    CHECK_NOTHROW(grafo.adiciona_aresta(1,2));
    grafo.imprime_grafo();
}

TEST_CASE("7 - Testando getter de adjacentes"){
    Grafo grafo(5);
    CHECK_NOTHROW(grafo.adiciona_aresta(0,1));
    CHECK_NOTHROW(grafo.adiciona_aresta(0,2));
    CHECK_NOTHROW(grafo.adiciona_aresta(0,3));
    CHECK_NOTHROW(grafo.adiciona_aresta(2,4));
    std::vector<Aresta> arestas=grafo.get_adjacentes(0);
    CHECK(arestas.size()==3);
}