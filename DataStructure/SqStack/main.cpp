#include "SqStack.h"

int main()
{
    int x;
    scanf("%d", &x);

    SqStack s;
    InitStack(s);
    while (x) {
        Push(s, x % 8);
        x = x / 8;
    }
    printf("SqStack的结果: ");
    while (!StackEmpty(s)) {
        int a;
        Pop(s, a);
        printf("%d", a);
    }
    puts("");

    DestroyStack(s);
    return 0;
}