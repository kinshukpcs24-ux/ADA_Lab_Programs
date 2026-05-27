#include <stdio.h>
#define MAX 50

void heapify(int a[MAX], int n)
{
    int i, j, k, v;
    for (i = n / 2; i >= 1; i--) {
        k = i;
        v = a[k];
        while (2 * k <= n) {
            j = 2 * k;
            if (j < n && a[j] < a[j + 1]) {
                j = j + 1;
            }
            if (v >= a[j]) {
                break;
            }
            a[k] = a[j];
            k = j;
        }
        a[k] = v;
    }
}

void heapsort(int a[MAX], int n)
{
    int i, temp;
    for (i = n; i > 1; i--) {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        heapify(a, i - 1);
    }
}

int main()
{
    int n, a[MAX];

    printf("Enter value of n: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    heapify(a, n);
    heapsort(a, n);

    printf("Array after performing heap sort:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
