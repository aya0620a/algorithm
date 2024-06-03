#include <stdio.h>

int main()
{
    int n;
    int v, j;
    int a[1000];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {   
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++)
    {
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;

        for(int k = 0; k < n; k++)
        {
            if(k == n-1)
                printf("%d", a[k]);
            else 
                printf("%d ", a[k]);
        }

        printf("\n");
    }

    return 0;
}