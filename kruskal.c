#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int src, dest, weight;
} Edge;

int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int compare(const void *a, const void *b) {
    Edge *edgeA = (Edge*)a;
    Edge *edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

void kruskal(int **graph, int V) {
    // First, extract edges from adjacency matrix
    int E = 0; // count edges
    for (int i = 0; i < V; i++)
        for (int j = i+1; j < V; j++) // upper triangle only, undirected graph
            if (graph[i][j] != 0 && graph[i][j] != INT_MAX)
                E++;

    Edge *edges = malloc(E * sizeof(Edge));
    int k = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i+1; j < V; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INT_MAX) {
                edges[k].src = i;
                edges[k].dest = j;
                edges[k].weight = graph[i][j];
                k++;
            }
        }
    }

    // Sort edges by weight
    qsort(edges, E, sizeof(Edge), compare);

    int *parent = malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int count = 0;  // edges added in MST
    int i = 0;

    printf("Edges in MST:\n");
    while (count < V - 1 && i < E) {
        Edge e = edges[i++];
        int set1 = find(parent, e.src);
        int set2 = find(parent, e.dest);

        if (set1 != set2) {
            printf("%d -- %d == %d\n", e.src, e.dest, e.weight);
            unionSets(parent, set1, set2);
            count++;
        }
    }

    free(parent);
    free(edges);
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Allocate adjacency matrix
    int **graph = malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = malloc(V * sizeof(int));
    }

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            // If no edge, store as INT_MAX (big number)
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INT_MAX;
        }

    kruskal(graph, V);

    // Free memory
    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
