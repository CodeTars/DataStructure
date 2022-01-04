#include "LinkList.h"

void InitList_L(LinkList& L)
{
    L = (LinkList)malloc(sizeof(Lnode));
    L->next = NULL;
}

void ClearList_L(LinkList& L)
{
    LinkList p = L->next;
    while (p) {
        LinkList q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

/* destroy a List */
void DestroyList_L(LinkList& L)
{
    ClearList_L(L);
    free(L);
    L = NULL;
}

void CreateList_L(LinkList& L, int n)
{
    InitList_L(L);

    for (int i = 0; i < n; i++) {
        LinkList p = (LinkList)malloc(sizeof(Lnode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

/* get the Length of List */
int ListLength_L(LinkList L)
{
    int n = 0;
    LinkList p = L->next;
    while (p) {
        ++n;
        p = p->next;
    }
    return n;
}

Status GetElem_L(LinkList L, int i, ElemType& e)
{
    LinkList p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }

    if (!p || i < 1)
        return ERROR;

    e = p->data;

    return OK;
}

/* insert a element */
Status ListInsert_L(LinkList& L, int i, ElemType e)
{
    LinkList p = L;
    /* to find the node at i-1 */
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    /* when i > 1 + the length of list, or i < 1 */
    if (!p || i < 1)
        return ERROR;

    LinkList q = (LinkList)malloc(sizeof(Lnode));
    q->data = e;

    q->next = p->next;
    p->next = q;

    return OK;
}

/* delete a element */
Status ListDelete_L(LinkList& L, int i, ElemType& e)
{
    LinkList p = L;
    /* to find the node at i-1 */
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }
    /* when i > the length of list, or i < 1 */
    if (!p->next || i < 1)
        return ERROR;

    LinkList q = p->next;
    e = q->data;
    p->next = p->next->next;

    free(q);
    return OK;
}

/* locate the element */
int LocateElem_L(LinkList L, ElemType e,
    Status (*compare)(ElemType, ElemType))
{
    LinkList p = L->next;
    int i = 1;
    while (p && !(*compare)(p->data, e)) {
        p = p->next;
        ++i;
    }
    /* if e is not the element of the list, return 0 */
    return p ? i : 0;
}

/* visit all nodes */
void ListTraverse_L(LinkList& L, void (*visit)(ElemType&))
{
    LinkList p = L->next;
    while (p) {
        (*visit)(p->data);
        p = p->next;
    }
}