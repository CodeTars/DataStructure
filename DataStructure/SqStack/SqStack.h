#include "ElemType_int.h"
#define STACK_INIT_SIZE 100
#define STACKINCREAMENT 10

typedef struct {
    ElemType* base;
    ElemType* top;
    int stacksize;
} SqStack;

Status InitStack(SqStack& S);

Status ClearStack(SqStack& S);

Status DestroyStack(SqStack& S);

Status StackEmpty(SqStack S);

int StackLength(SqStack S);

Status GetTop(SqStack S, ElemType& e);

Status Push(SqStack& S, ElemType e);

Status Pop(SqStack& S, ElemType& e);

void StackTraverse(SqStack& S, void (*visit)(ElemType&));
