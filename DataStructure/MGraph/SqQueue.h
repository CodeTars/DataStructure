#include "PreDefined.h"

#define MAXQSIZE 20

typedef int QElemType;

typedef struct  
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;


Status InitQueue(SqQueue &Q);
Status DestroyQueue(SqQueue &Q);
Status EnQueue(SqQueue &Q, QElemType e);
Status DeQueue(SqQueue &Q, QElemType &e);
Status QueueEmpty(SqQueue Q);