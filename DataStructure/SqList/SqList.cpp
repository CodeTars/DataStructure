#include "SqList.h"

Status InitList_Sq(SqList& L)
{
    L.elem = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (L.elem == NULL) {
        exit(OVERFLOW);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

Status ClearList_Sq(SqList& L)
{
    L.length = 0;
    return OK;
}

Status DestroyList_Sq(SqList& L)
{
    free(L.elem);
    L.elem = NULL;

    L.length = 0;
    L.listsize = 0;

    return OK;
}

int ListLength_Sq(SqList L)
{
    return L.length;
}

Status GetElem_Sq(SqList L, int i, ElemType& e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}

Status ListInsert_Sq(SqList& L, int i, ElemType e)
{
    /* make sure i in [1, length + 1] */
    if (i < 1 || i > L.length + 1)
        return ERROR;

    /* make sure L.lenght < L.listsize */
    if (L.length >= L.listsize) {
        ElemType* newbase = (ElemType*)realloc(L.elem, sizeof(ElemType) * (L.listsize + LISTINCREMENT));
        if (newbase == NULL)
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }

    // ElemType *p = L.elem + i - 1;
    // ElemType *q = L.elem + L.length;
    // while(q > p) { *q = *(q - 1); --q }
    // *p = e;

    for (int k = L.length; k > i - 1; k--) {
        L.elem[k] = L.elem[k - 1];
    }
    L.elem[i - 1] = e;
    ++L.length;
    return OK;
}

Status ListDelete_Sq(SqList& L, int i, ElemType& e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];

    for (int k = i - 1; k < L.length - 1; k++) {
        L.elem[k] = L.elem[k + 1];
    }
    --L.length;
    return OK;
}

int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    int i;
    for (i = 1; i <= L.length; i++) {
        if ((*compare)(L.elem[i - 1], e) == TRUE) {
            break;
        }
    }
    if (i > L.length)
        return 0;
    return i;
}

void ListTraverse_Sq(SqList& L, void (*vist)(ElemType&))
{
    for (int i = 0; i < L.length; i++) {
        (*vist)(L.elem[i]);
    }
}