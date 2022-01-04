#include "ElemType_int.h"

typedef struct Snode {
    ElemType data;
    Snode* next;
} Snode, *LinkStack;

Status ClearStack(LinkStack& S);
Status DestroyStack(LinkStack& S);
int StackLength(LinkStack S);
Status GetTop(LinkStack S, ElemType& e);
Status Push(LinkStack& S, ElemType e);
Status Pop(LinkStack& S, ElemType& e);

Status InitStack(LinkStack& S);
Status StackEmpty(LinkStack S);
void StackTraverse(LinkStack& S, void (*visit)(ElemType&));
