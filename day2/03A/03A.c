#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int top = -1;
int stack[100];

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main (){
    int x;
    char formula[100];
    
    while (scanf("%s", formula) != EOF)
    {
        if (formula[0] =='+')
        {
            int x = pop();
            int y = pop();
            push(x + y);
        }
        else if (formula[0] == '-')
        {
            int y = pop();
            int x = pop();
            push(x - y);
        }
        else if (formula[0] == '*')
        {
            int y = pop();
            int x = pop();
            push(x * y);
        }
        else{
            //文字列を数値に変換
            push(atoi(formula));
        }
    }

    printf("%d\n", pop());

    return 0;
}