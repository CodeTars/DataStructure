#include "LinkStack.h"

int main()
{
    int x;
    scanf("%d", &x);

    LinkStack s;
    InitStack(s);
    while (x) {
        Push(s, x % 8);
        x = x / 8;
    }
    printf("LinkStack的结果: ");
    while (!StackEmpty(s)) {
        int a;
        Pop(s, a);
        printf("%d", a);
    }
    puts("");

    DestroyStack(s);
    return 0;
}