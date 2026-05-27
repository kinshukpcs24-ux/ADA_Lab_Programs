#include <stdio.h>

void main()
{
    int n = 0;
    printf("Enter number of vertices in graph : ");
    scanf("%d",&n);

    int G[n][n];

    int i, j;
    printf("Enter weighted adjacency matrix :\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&G[i][j]);
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(G[i][j]>(G[i][k]+G[k][j]))
                    G[i][j] = G[i][k] + G[k][j];
            }
        }
    }
    printf("Shortest distance matrix :\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
}
