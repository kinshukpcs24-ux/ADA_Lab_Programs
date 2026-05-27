#include <stdio.h>

#define MAX 10

int main() {
    int cost[MAX][MAX], visited[MAX] = {0};
    int n, i, j;
    int ne = 1;
    int min, mincost = 0;
    int a, b, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[0] = 1;

    printf("\nEdges of Minimum Spanning Tree:\n");

    while (ne < n) {
        min = 999;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (!visited[v]) {
            printf("%d edge (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
            visited[v] = 1;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
