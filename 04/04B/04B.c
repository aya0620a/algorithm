#include <stdio.h>

int binarySearch(int S[], int n, int key){
    int left = 0;
    int right = n;
    int mid;

    while (left < right)
    {
        mid = (left + right) / 2;

        if (S[mid] == key)
        {   
            return 1;
        }
        if (key < S[mid])
        {
            right = mid;
        }
        else if (key > S[mid])
        {
            left = mid + 1;
        }
    }
    return 0;
}


int main(){

    int n, q;
    scanf("%d", &n);
    int S[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    int T[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }

    int count = 0;

    for (int i = 0; i < q; i++)
    {
        if (binarySearch(S, n, T[i]))
        {
            count++;
        }
    }
    
    

    printf("%d\n", count);

    return 0;
}