#include <stdio.h>

void main()
{
    int n,i;
    int cap;
    printf("Enter the number of items : ");
    scanf("%d",&n);
    printf("Enter knapsack capacity : ");
    scanf("%d",&cap);

    int p[n];
    int w[n];
    float r[n];

    printf("Enter their profits : ");
    for(i=0; i<n; i++)
        scanf("%d ",&p[i]);

    printf("Enter their weights : ");
    for(i=0; i<n; i++)
        scanf("%d ",&w[i]);

    for(i=0; i<n; i++)
        r[i] = (float)(p[i]/w[i]);

    float temp_float = 0.0;
    int temp_int = 0;
    int TotProfit = 0;

    for(i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(r[i]<r[j])
            {
                temp_float = r[j];
                r[j] = r[i];
                r[i] = temp_float;

                temp_int = w[j];
                w[j] = w[i];
                w[i] = temp_int;

                temp_int = p[j];
                p[j] = p[i];
                p[i] = temp_int;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(w[i]>cap)
            break;
        else
        {
            TotProfit += p[i];
            cap -= w[i];
        }
    }

    if(i<n)
        TotProfit += (r[i]*cap);

    printf("Maximum Profit : %d",TotProfit);
}
