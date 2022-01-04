#include "BiTree.h"

BiTree CreateBiTreePreOrder(TElemType* S, int& i)
{
    if (S[i] == '#') {
        ++i;
        return NULL;
    } else {
        BiTNode* T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = S[i++];
        T->leftChild = CreateBiTreePreOrder(S, i);
        T->rightChild = CreateBiTreePreOrder(S, i);
        return T;
    }
}

BiTree CreateBiTreePreIn(TElemType* prelist, int p1, int p2, TElemType* inlist, int i1, int i2)
{
    if (p1 > p2 || i1 > i2) {
        return NULL;
    } else {
        int k = 0;
        while (prelist[p1] != inlist[i1 + k]) {
            ++k;
        }
        BiTree T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = prelist[p1];
        T->leftChild = CreateBiTreePreIn(prelist, p1 + 1, p1 + k, inlist, i1, i1 + k - 1);
        T->rightChild = CreateBiTreePreIn(prelist, p1 + k + 1, p2, inlist, i1 + k + 1, i2);
        return T;
    }
}

BiTree CreateBiTreeInPost(TElemType* inlist, int i1, int i2, TElemType* postlist, int p1, int p2)
{
    if (p1 > p2 || i1 > i2) {
        return NULL;
    } else {
        int k = 0;
        while (postlist[p2] != inlist[i1 + k]) {
            ++k;
        }
        BiTree T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = postlist[p2];
        T->leftChild = CreateBiTreeInPost(inlist, i1, i1 + k - 1, postlist, p1, p1 + k - 1);
        T->rightChild = CreateBiTreeInPost(inlist, i1 + k + 1, i2, postlist, p1 + k, p2 - 1);
        return T;
    }
}

Status PreOrderTraverse(BiTree& T, Status (*visit)(TElemType&))
{
    if (T) {
        if (visit(T->data) == ERROR) {
            return ERROR;
        }
        PreOrderTraverse(T->leftChild, visit);
        PreOrderTraverse(T->rightChild, visit);
    }
    return OK;
}

Status InOrderTraverse(BiTree& T, Status (*visit)(TElemType&))
{
    if (T) {
        InOrderTraverse(T->leftChild, visit);
        if (visit(T->data) == ERROR) {
            return ERROR;
        }
        InOrderTraverse(T->rightChild, visit);
    }
    return OK;
}

Status PostOrderTraverse(BiTree& T, Status (*visit)(TElemType&))
{
    if (T) {
        PostOrderTraverse(T->leftChild, visit);
        PostOrderTraverse(T->rightChild, visit);
        if (visit(T->data) == ERROR) {
            return ERROR;
        }
    }
    return OK;
}

Status PrintElement(TElemType& e)
{
    if (putchar(e) == EOF) {
        return ERROR;
    } else {
        return OK;
    }
}

#define max(a, b) ((a) > (b) ? (a) : (b))
int PostOrderDepth(BiTree T)
{
    if (T == NULL) {
        return 0;
    } else {
        int dl = PostOrderDepth(T->leftChild);
        int dr = PostOrderDepth(T->rightChild);
        return 1 + max(dl, dr);
    }
}

int PostOrderCount(BiTree T)
{
    if (T == NULL) {
        return 0;
    } else {
        return 1 + PostOrderCount(T->leftChild) + PostOrderCount(T->rightChild);
    }
}

void PreOrderDestroy(BiTree& T)
{
    if (T) {
        BiTree l = T->leftChild;
        BiTree r = T->rightChild;
        free(T);
        PreOrderDestroy(l);
        PreOrderDestroy(r);
    }
}

void InOrderChildren(BiTree T)
{
    if (T) {
        InOrderChildren(T->leftChild);
        printf("%c's children: (%c, %c)\n", T->data,
            T->leftChild ? T->leftChild->data : '#', //若空则输出#
            T->rightChild ? T->rightChild->data : '#');
        InOrderChildren(T->rightChild);
    }
}

void InOrderParent(BiTree T, BiTree PT)
{
    if (T) {
        InOrderParent(T->leftChild, T);
        printf("%c's parent: %c\n", T->data,
            PT ? PT->data : '#'); //若空则输出#
        InOrderParent(T->rightChild, T);
    }
}

void InOrderLevel(BiTree T, int level)
{
    if (T) {
        InOrderLevel(T->leftChild, level + 1);
        printf("%c's level: %d\n", T->data, level);
        InOrderLevel(T->rightChild, level + 1);
    }
}