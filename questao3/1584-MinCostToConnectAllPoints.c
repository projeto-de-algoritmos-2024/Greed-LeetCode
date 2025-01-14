#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estrutura para representar um conjunto disjunto (Union-Find)
typedef struct {
    int *parent;
    int *rank;
    int n;
} UnionFind;

// Função para inicializar a estrutura Union-Find
UnionFind* createUnionFind(int n) {
    UnionFind *uf = (UnionFind*) malloc(sizeof(UnionFind));
    uf->parent = (int*) malloc(n * sizeof(int));
    uf->rank = (int*) malloc(n * sizeof(int));
    uf->n = n;
    
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 1;
    }
    return uf;
}

// Função para encontrar o representante do conjunto de um elemento
int find(UnionFind *uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]); // Compressão de caminho
    }
    return uf->parent[x];
}

// Função para unir dois conjuntos
int unionSets(UnionFind *uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);
    
    if (rootX != rootY) {
        // União por rank
        if (uf->rank[rootX] > uf->rank[rootY]) {
            uf->parent[rootY] = rootX;
        } else if (uf->rank[rootX] < uf->rank[rootY]) {
            uf->parent[rootX] = rootY;
        } else {
            uf->parent[rootY] = rootX;
            uf->rank[rootX]++;
        }
        return 1;
    }
    return 0;
}

// Função para calcular a distância de Manhattan entre dois pontos
int manhattanDistance(int* p1, int* p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

// Função para comparar as arestas (usada para ordenar as arestas)
int compare(const void *a, const void *b) {
    int* edgeA = *(int**)a;
    int* edgeB = *(int**)b;
    return edgeA[2] - edgeB[2]; // Compara pelo custo
}

// Função para calcular o custo mínimo para conectar todos os pontos
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int edgeCount = n * (n - 1) / 2;
    int **edges = (int**) malloc(edgeCount * sizeof(int*));
    
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges[index] = (int*) malloc(3 * sizeof(int));
            edges[index][0] = i;
            edges[index][1] = j;
            edges[index][2] = manhattanDistance(points[i], points[j]);
            index++;
        }
    }

    // Ordena as arestas pela distância
    qsort(edges, edgeCount, sizeof(int*), compare);
    
    UnionFind *uf = createUnionFind(n);
    int totalCost = 0;
    int edgesUsed = 0;
    
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int cost = edges[i][2];
        
        // Se os pontos u e v não estão no mesmo conjunto, conecta-os
        if (unionSets(uf, u, v)) {
            totalCost += cost;
            edgesUsed++;
            if (edgesUsed == n - 1) {  // Se já usamos n-1 arestas, terminamos
                free(uf->parent);
                free(uf->rank);
                free(uf);
                for (int j = 0; j < edgeCount; j++) {
                    free(edges[j]);
                }
                free(edges);
                return totalCost;
            }
        }
    }
    
    free(uf->parent);
    free(uf->rank);
    free(uf);
    for (int i = 0; i < edgeCount; i++) {
        free(edges[i]);
    }
    free(edges);
    
    return -1;  // Se não for possível conectar todos os pontos
}