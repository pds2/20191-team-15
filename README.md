# 20191-team-15

## Biblioteca de Grafos

  O objetivo deste projeto é implementar uma biblioteca que resolve problemas modelados em grafos através de alguns de seus algoritmos mais populares como:
*	Busca em profundidade
*	Busca em Largura
* Emparelhamento
*	Caminhos mais curtos (Djikstra, Bellman-Ford e Johnson)
*	Árvore Geradora Mínima (Prim e Kruskal)

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
