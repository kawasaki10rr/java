#include <stdio.h>
#define INF 99999
#define MAX 100

int main() {
    int n, i, j, k;
    int dist[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    // Floyd's algorithm
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if ( dist[k][j] + dist[i][k]< dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("All-Pairs Shortest Path Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}