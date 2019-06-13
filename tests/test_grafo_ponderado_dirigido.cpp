#include "doctest.h"
#include "grafo_ponderado_dirigido.h"

TEST_CASE("0 - Teste de construtor"){
CHECK_THROWS(GrafoPonderadoDirigido grafo(-1));
CHECK_NOTHROW(GrafoPonderadoDirigido grafo(3));
}

TEST_CASE("1 - Testando adicao de arestas"){
    GrafoPonderadoDirigido grafo(3);
    grafo.adiciona_aresta(0,1,3);
    grafo.adiciona_aresta(1,2,4);
    grafo.adiciona_aresta(0,2,2);
    grafo.adiciona_aresta(2,0,1);
    CHECK(grafo.get_num_arestas()==4);
}

TEST_CASE("2 - Testando adicao de arestas invalidas"){
    GrafoPonderadoDirigido grafo(4);
    CHECK_THROWS(grafo.adiciona_aresta(0,9,5));
    CHECK_THROWS(grafo.adiciona_aresta(0,-6,2));
    CHECK_THROWS(grafo.adiciona_aresta(12,1,3));
    CHECK_THROWS(grafo.adiciona_aresta(-2,3,4));
    CHECK(grafo.get_num_arestas()==0);
    CHECK(grafo.get_peso_total()==0);
}

TEST_CASE("3 - Testando peso total"){
    GrafoPonderadoDirigido grafo(4);
    grafo.adiciona_aresta(0,1,8);
    grafo.adiciona_aresta(0,2,1);
    grafo.adiciona_aresta(1,2,5);
    grafo.adiciona_aresta(0,3,4);
    grafo.adiciona_aresta(3,0,7);
    CHECK(grafo.get_peso_total()==25);
}

TEST_CASE("4 - Testando adicao de arestas com pesos invalidos"){
    GrafoPonderadoDirigido grafo(4);
    CHECK_THROWS(grafo.adiciona_aresta(0,2,-10));
    CHECK_THROWS(grafo.adiciona_aresta(0,1,-2));
    CHECK_THROWS(grafo.adiciona_aresta(3,1,-9));
    CHECK_THROWS(grafo.adiciona_aresta(1,3,-6));
    CHECK(grafo.get_num_arestas()==0);
    CHECK(grafo.get_peso_total()==0);
}

TEST_CASE("5 - Testando adicao de arestas já existentes"){
    GrafoPonderadoDirigido grafo(3);
    CHECK_NOTHROW(grafo.adiciona_aresta(0,2,1));
    CHECK_NOTHROW(grafo.adiciona_aresta(0,1,5));
    CHECK_THROWS(grafo.adiciona_aresta(0,1,9));
    CHECK_NOTHROW(grafo.adiciona_aresta(2,0,5));
    CHECK(grafo.get_num_arestas()==3);
    CHECK(grafo.get_peso_total()==11);
}