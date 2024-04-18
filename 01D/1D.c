#include <stdio.h>

long int maxProfit(int prices[], int n) {

    int min = prices[0];
    int max = prices[1] - prices[0];

    for (int i = 1; i < n; i++) {
        int current = prices[i] - min;
        if (current > max) {
            max = current;
        }
        if (prices[i] < min) {
            min = prices[i];
        }
    }

    return max;
}

int main() 
{
    int n;
    scanf("%d", &n);
    int prices[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    printf("%d\n", maxProfit(prices, n));

    return 0;
}