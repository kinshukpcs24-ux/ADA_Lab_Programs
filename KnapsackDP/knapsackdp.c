#include <stdio.h>

#define MAX 10

int max(int a, int b);
void knapsackDP(int n, int M);

int Table[MAX+1][MAX+1];
int P[MAX];
int W[MAX];

void main()
{
    int n, M, i, j;
    printf("Enter number of objects and capacity of knapsack : ");
    scanf("%d %d",&n,&M);

    printf("Enter the weights : ");
    for(i=0; i<n; i++)
        scanf("%d",&W[i]);

    printf("Enter the profits : ");
    for(i=0; i<n; i++)
        scanf("%d",&P[i]);

    knapsackDP(n,M);
    printf("Table :\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<M; j++)
        {
            printf("%d ",Table[i][j]);
        }
        printf("\n");
    }
    printf("\nOptimal Value : %d",Table[i-1][j-1]);
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

void knapsackDP(int n, int M)
{
    for(int i=0; i<n; i++)
        Table[i][0] = 0;

    for(int j=0; j<M; j++)
        Table[0][j] = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(j<W[i])
            {
                Table[i][j] = Table[i-1][j];
            }
            else
            {
                Table[i][j] = max(Table[i-1][j],P[i]+Table[i-1][j-W[i]]);
            }
        }
    }
}
