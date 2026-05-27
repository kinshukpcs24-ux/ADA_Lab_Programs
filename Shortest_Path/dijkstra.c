#include <stdio.h>
#define INF 99999
#define MAX 100

void dijkstra(int c[MAX][MAX], int n, int s, int d[MAX]) {
    int v[MAX], i, j, u, min;

    for (i = 1; i <= n; i++) {
        d[i] = c[s][i];
        v[i] = 0;
    }
    v[s] = 1;

    for (i = 1; i <= n - 1; i++) {
        min = INF;
        u = -1;

        for (j = 1; j <= n; j++) {
            if (v[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        if (u == -1) break;
        v[u] = 1;

        for (j = 1; j <= n; j++) {
            if (v[j] == 0 && (d[u] + c[u][j]) < d[j]) {
                d[j] = d[u] + c[u][j];
            }
        }
    }
}

int main() {
    int n, i, j, s;
    int c[MAX][MAX], d[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use %d for INF):\n", INF);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    dijkstra(c, n, s, d);

    printf("Shortest distances from source %d:\n", s);
    for (i = 1; i <= n; i++) {
        if (d[i] == INF)
            printf("%d -> %d : INF\n", s, i);
        else
            printf("%d -> %d : %d\n", s, i, d[i]);
    }

    return 0;
}
