#include "doctest.h"
#include "grafo_ponderado.h"

TEST_CASE("0 - Teste de construtor"){
    CHECK_THROWS(GrafoPonderado grafo(-1));
    CHECK_NOTHROW(GrafoPonderado grafo(3));
}

TEST_CASE("1 - Testando adicao de arestas"){
    GrafoPonderado grafo(3);
    grafo.adiciona_aresta(0,1,3);
    grafo.adiciona_aresta(1,2,4);
    grafo.adiciona_aresta(2,0,1);
    CHECK(grafo.get_num_arestas()==3);
}

TEST_CASE("2 - Testando adicao de arestas invalidas"){
    GrafoPonderado grafo(4);
    CHECK_THROWS(grafo.adiciona_aresta(0,5,1));
    CHECK_THROWS(grafo.adiciona_aresta(0,-1,2));
    CHECK_THROWS(grafo.adiciona_aresta(8,1,3));
    CHECK_THROWS(grafo.adiciona_aresta(-5,3,5));
    CHECK(grafo.get_num_arestas()==0);
    CHECK(grafo.get_peso_total()==0);
}

TEST_CASE("3 - Testando peso total"){
    GrafoPonderado grafo(4);
    grafo.adiciona_aresta(0,1,2);
    grafo.adiciona_aresta(0,2,1);
    grafo.adiciona_aresta(1,2,5);
    grafo.adiciona_aresta(0,3,4);
    CHECK(grafo.get_peso_total()==12);
}

TEST_CASE("4 - Testando adicao de arestas com pesos invalidos"){
    GrafoPonderado grafo(7);
    CHECK_THROWS(grafo.adiciona_aresta(0,2,-1));
    CHECK_THROWS(grafo.adiciona_aresta(0,1,-20));
    CHECK_THROWS(grafo.adiciona_aresta(3,1,-4));
    CHECK_THROWS(grafo.adiciona_aresta(5,3,-4));
    CHECK(grafo.get_num_arestas()==0);
    CHECK(grafo.get_peso_total()==0);
}

TEST_CASE("5 - Testando adicao de arestas já existentes"){
    GrafoPonderado grafo(7);
    CHECK_NOTHROW(grafo.adiciona_aresta(0,2,1));
    CHECK_NOTHROW(grafo.adiciona_aresta(0,1,5));
    CHECK_THROWS(grafo.adiciona_aresta(0,1,9));
    CHECK_THROWS(grafo.adiciona_aresta(2,0,5));
    CHECK(grafo.get_num_arestas()==2);
    CHECK(grafo.get_peso_total()==6);
}

TEST_CASE("6 - Testando AGM"){
    GrafoPonderado grafo(6);
    CHECK_NOTHROW(grafo.adiciona_aresta(0,2,1));
    CHECK_NOTHROW(grafo.adiciona_aresta(0,1,5));
    CHECK_THROWS(grafo.adiciona_aresta(0,1,9));
    CHECK_THROWS(grafo.adiciona_aresta(2,0,5));
    GrafoPonderado g2=grafo.arvore_geradora_minima();
    CHECK(g2.get_num_vertices()==6);
    CHECK(g2.get_num_arestas()==2);
    CHECK(g2.get_peso_total()==7);
}