#include <stdio.h>

#define MAX 100

int count = 0;

//バブルソート
void bubbleSort(int array[MAX], int n) {
    int flag = 1;
    int tmp;
    int index;
    while(flag){
        flag = 0;
        index = 0;
        for(int j = n - 1; j > index; j--){
            if(array[j] < array[j - 1]){
                tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
                flag = 1;
                count++;
                index++;
            }
        }
    
    }
}

int main(void){
    int len;

    scanf("%d", &len);

    int array[MAX];

    for(int i = 0; i < len; i++){
        scanf("%d", &array[i]);
    }
    
    bubbleSort(array, len);

    //出力
    for(int i = 0; i < len; i++){
        if(i == len - 1){
            printf("%d", array[i]);
        }
        else{
            printf("%d ", array[i]);
        }
    }
    printf("\n");

    printf("%d\n", count);

    return 0;
}
