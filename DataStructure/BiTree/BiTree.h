#include "PreDefined.h"

typedef char TElemType;

typedef struct BiTNode {
    TElemType data = '\0';
    BiTNode* leftChild = NULL;
    BiTNode* rightChild = NULL;
} BiTNode, *BiTree;

BiTree CreateBiTreePreOrder(TElemType* S, int& i);
BiTree CreateBiTreePreIn(TElemType* prelist, int p1, int p2, TElemType* inlist, int i1, int i2);
BiTree CreateBiTreeInPost(TElemType* inlist, int i1, int i2, TElemType* postlist, int p1, int p2);
Status PreOrderTraverse(BiTree& T, Status (*visit)(TElemType&));
Status InOrderTraverse(BiTree& T, Status (*visit)(TElemType&));
Status PostOrderTraverse(BiTree& T, Status (*visit)(TElemType&));
Status PrintElement(TElemType& e);
int PostOrderDepth(BiTree T);
int PostOrderCount(BiTree T);
void PreOrderDestroy(BiTree& T);
void InOrderChildren(BiTree T);
void InOrderParent(BiTree T, BiTree PT);
void InOrderLevel(BiTree T, int level);
