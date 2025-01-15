#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int *parent;
    int *rank;
    int n;
} UnionFind;

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

int find(UnionFind *uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]); 
    }
    return uf->parent[x];
}

int unionSets(UnionFind *uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);
    
    if (rootX != rootY) {
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

int manhattanDistance(int* p1, int* p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

int compare(const void *a, const void *b) {
    int* edgeA = *(int**)a;
    int* edgeB = *(int**)b;
    return edgeA[2] - edgeB[2]; 
}

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

    qsort(edges, edgeCount, sizeof(int*), compare);
    
    UnionFind *uf = createUnionFind(n);
    int totalCost = 0;
    int edgesUsed = 0;
    
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int cost = edges[i][2];
        
        if (unionSets(uf, u, v)) {
            totalCost += cost;
            edgesUsed++;
            if (edgesUsed == n - 1) {  
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
    
    return -1;  
}