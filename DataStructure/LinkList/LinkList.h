#include "ElemType_int.h"

typedef struct Lnode {
	ElemType data;
	Lnode *next;
}Lnode, *LinkList;

void InitList_L(LinkList &L);

void ClearList_L(LinkList &L);

void DestroyList_L(LinkList &L);

void CreateList_L(LinkList &L, int n);

int ListLength_L(LinkList L);

Status GetElem_L(LinkList L, int i, ElemType &e);

Status ListInsert_L(LinkList &L, int i, ElemType e);

Status ListDelete_L(LinkList &L, int i, ElemType &e);

int LocateElem_L(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));

void ListTraverse_L(LinkList &L, void (*visit)(ElemType &));
