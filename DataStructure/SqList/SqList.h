#include "ElemType_int.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList &L);

Status ClearList_Sq(SqList &L);

Status DestroyList_Sq(SqList &L);

int ListLength_Sq(SqList L);

Status GetElem_Sq(SqList L, int i, ElemType &e);

Status ListInsert_Sq(SqList &L, int i, ElemType e);

Status ListDelete_Sq(SqList &L, int i, ElemType &e);

int LocateElem_Sq(SqList L, ElemType e, Status (*compare) (ElemType, ElemType));

void ListTraverse_Sq(SqList &L, void (*vist) (ElemType &));