#include "SqQueue.h"

Status InitQueue(SqQueue& Q)
{
    Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base)
        exit(OVERFLOW);

    Q.front = Q.rear = 0;

    return OK;
}

Status DestroyQueue(SqQueue& Q)
{
    if (Q.base) {
        free(Q.base);
        Q.base = NULL;
    }

    Q.front = Q.rear = 0;

    return OK;
}

Status EnQueue(SqQueue& Q, QElemType e)
{
    if (Q.rear == MAXQSIZE)
        return ERROR;

    Q.base[Q.rear] = e;
    Q.rear++;

    return OK;
}

Status DeQueue(SqQueue& Q, QElemType& e)
{
    if (Q.front == Q.rear)
        return ERROR;

    e = Q.base[Q.front];
    Q.front++;

    return OK;
}

Status QueueEmpty(SqQueue Q)
{
    if (Q.front == Q.rear) {
        return true;
    } else {
        return false;
    }
}