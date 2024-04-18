#include <stdio.h>
#include <math.h>

int main(){
    int n, flag;
    int count = 0;
    int a[10000];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int j = 0; j < n; j++){
        flag = 1;
        for (int k = 2; k <= sqrt(a[j]); k++)
        {
            if(a[j] % k == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1 && a[j] != 1){
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}