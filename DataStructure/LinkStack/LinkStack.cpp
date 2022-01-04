#include "LinkStack.h"

/* 清空 */
Status ClearStack(LinkStack& S)
{
    LinkStack p = S->next;
    while (p) {
        LinkStack q = p->next;
        free(p);
        p = q;
    }
    S->next = NULL;
    return OK;
}

/* 销毁 */
Status DestroyStack(LinkStack& S)
{
    ClearStack(S);
    free(S);
    S = NULL;
    return OK;
}

/* 求栈长 */
int StackLength(LinkStack S)
{
    int n = 0;
    LinkStack p = S->next;
    while (p) {
        ++n;
        p = p->next;
    }
    return n;
}

/* 取栈顶元素 */
Status GetTop(LinkStack S, ElemType& e)
{
    if (S->next == NULL) {
        return ERROR;
    }
    e = S->next->data;
    return OK;
}

/* 进栈 */
Status Push(LinkStack& S, ElemType e)
{
    LinkStack p = (LinkStack)malloc(sizeof(ElemType));
    p->data = e;
    p->next = S->next;
    S->next = p;
    return OK;
}

/* 出栈 */
Status Pop(LinkStack& S, ElemType& e)
{
    LinkStack p = S->next;
    if (p == NULL) {
        return ERROR;
    }
    e = p->data;
    S->next = p->next;
    free(p);
    return OK;
}

Status InitStack(LinkStack& S)
{
    S = (LinkStack)malloc(sizeof(ElemType));
    S->next = NULL;
    return OK;
}

Status StackEmpty(LinkStack S)
{
    return S->next == NULL ? TRUE : FALSE;
}

void StackTraverse(LinkStack& S, void (*visit)(ElemType&))
{
    LinkStack p = S->next;
    while (p) {
        (*visit)(p->data);
        p = p->next;
    }
}
