#include <stdio.h>

int linerSearch(int A[], int n, int key){
    int i = 0;
    A[n] = key;
    while (A[i] != key){
        i++;
    }
    return i != n;
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

    for (int i = 0; i < q; i++) {
        if (linerSearch(S, n, T[i])) {
            count++;
        }
    }

    printf("%d\n", count);


    return 0;
}