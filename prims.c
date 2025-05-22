#include <stdio.h>
#include <stdlib.h>
#define INF 9999

void prims(int n, int cost[100][100]);

int main() {
    int n;
    int cost[100][100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    prims(n, cost);

    return 0;
}

void prims(int n, int cost[100][100]) {
    int visited[100] = {0};
    int edge_count = 0;
    int total_cost = 0;

    visited[0] = 1; // Start from vertex 0

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edge_count < n - 1) {
        int min = INF;
        int a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("Edge %d: (%d -> %d) cost = %d\n", edge_count + 1, a, b, min);
            visited[b] = 1;
            total_cost += min;
            edge_count++;
        }
    }

    printf("Total cost of Minimum Spanning Tree = %d\n", total_cost);
}
