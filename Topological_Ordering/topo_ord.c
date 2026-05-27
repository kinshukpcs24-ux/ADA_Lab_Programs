#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main() {
    int n, i, j;
    int graph[MAX][MAX];
    int indegree[MAX], topo[MAX];
    int queue[MAX], front = 0, rear = -1;
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        for (j = 0; j < n; j++) {
            indegree[i]+=graph[j][i];
        }
        if (indegree[i] == 0)
            queue[++rear] = i;
    }

    while (front <= rear) {
        int vertex = queue[front++];
        topo[count++] = vertex;

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1)
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    if (count == n) {
        printf("Topological Order: ");
        for (i = 0; i < n; i++) {
            printf("%d ", topo[i]+1);
        }
    } else {
        printf("Graph has a cycle. Topological order not possible.\n");
    }

    return 0;
}
