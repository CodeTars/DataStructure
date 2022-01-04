#include "SqStack.h"

/* 清空 */
Status ClearStack(SqStack& S)
{
    S.top = S.base;
    return OK;
}

/* 销毁 */
Status DestroyStack(SqStack& S)
{
    free(S.base);
    S.top = S.base = NULL;
    S.stacksize = 0;
    return OK;
}

/* 求栈长 */
int StackLength(SqStack S)
{
    return S.top - S.base;
}

/* 取栈顶元素 */
Status GetTop(SqStack S, ElemType& e)
{
    if (S.top == S.base) {
        return ERROR;
    }
    e = *(S.top - 1);
    return OK;
}

/* 进栈 */
Status Push(SqStack& S, ElemType e)
{
    if (S.top - S.base == S.stacksize) {
        S.base = (ElemType*)realloc(S.base,
            sizeof(ElemType) * (S.stacksize + STACKINCREAMENT));
        if (!S.base) {
            exit(OVERFLOW);
        }
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREAMENT;
    }
    *S.top++ = e;
    return OK;
}

/* 出栈 */
Status Pop(SqStack& S, ElemType& e)
{
    if (S.top == S.base) {
        return ERROR;
    }
    e = *--S.top;
    return OK;
}

Status InitStack(SqStack& S)
{
    S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S.base) {
        exit(OVERFLOW);
    }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status StackEmpty(SqStack S)
{
    return S.base == S.top ? TRUE : FALSE;
}

void StackTraverse(SqStack& S, void (*visit)(ElemType&))
{
    ElemType* p = S.base;
    while (p < S.top) {
        (*visit)(*p++);
    }
}
