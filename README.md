# Biblioteca de Grafos

## Objetivo
  O objetivo deste projeto é implementar uma biblioteca que resolve problemas modelados em grafos através de alguns de seus algoritmos mais populares como:
*	Busca em profundidade
*	Busca em Largura
*	Caminhos mais curtos (Djikstra e Bellman-Ford)
*	Árvore Geradora Mínima 

## Instruções de uso
> Programa desenvolvido e Testes executados em ambiente linux.

> Compilar o programa:
* make

> Compilar e rodar o programa:
* make run

> Compilar e rodar os testes:
* make tests

## Já implementado
> Grafo com arestas sem pesos e direção
* Adição de arestas
* Verificação se o grafo é conexo.
* Impressão do grafo

> Grafo com arestas com peso e sem direção
* Árvore geradora mínima

>Grafo com arestas com peso positivo e com direção
* Caminho mais curto de uma origem para todos os vertices

## Em construção
> Implementação de grafos com pesos negativos nas arestas.
> Tratamento de caminhos mais curtos em grafos com pesos negativos nas arestas com o algoritmo de Bellman-Ford.

## User Stories
> Como usuário gostaria de otimizar o uso de cabeamento em uma rede que modelei como um grafo não orientado e ponderado.
* Receber e armazenar o grafo ponderado e não orientado informado pelo usuário
*	Gerar a AGM do grafo informado

> Como usuário gostaria de calcular o menor caminho do ponto A ao ponto B em uma rede de ruas de mão única.
* Receber e armazenar o grafo ponderado e orientado informado pelo usuário
* Rodar o algoritmo de dijkstra para encontrar o menor caminho entre os dois pontos

> Como usuário gostaria de adicionar uma aresta em um grafo criado.
* Receber a aresta a ser adicionada
* Adicionar a aresta ao grafo

> Como usuário gostaria de remover um vértice do grafo criado.
* Receber o vértice a ser removido
* Remover as arestas adjacentes ao vértice
* Remover o vértice

> Como usuário gostaria de encontrar o menor caminho entre dois vértices em um grafo ponderado e direcionado que contém pesos negativos nas arestas.
* Receber e armazenar o grafo ponderado e orientado informado pelo usuário
* Rodar o algoritmo de Bellman-Ford para encontrar o menor caminho entre os dois vértices

>Como usuário eu gostaria de encontrar o caminho da entrada até a saída de um labirinto que foi modelado em um grafo não ponderado e não orientado
* Receber e armazenar o grafo não ponderado e não orientado informado pelo usuário
* Rodar o algoritmo da busca em profundidade para encontrar o caminho até a saída
