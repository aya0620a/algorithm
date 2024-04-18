#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    int result = gcd(x, y);
    
    printf("%d\n", result);

    return 0;
}
