#include "BiTree.h"

int main()
{
    TElemType S[] = "ABH##FD###E#CK##G##";
    TElemType prelist[] = "ABHFDECKG"; // 0 ~ 8
    TElemType inlist[] = "HBDFAEKCG";
    TElemType postlist[] = "HDFBKGCEA";

    int i = 0;
    BiTree T = CreateBiTreePreOrder(S, i = 0);
    // BiTree T = CreateBiTreePreIn(prelist, 0, 8, inlist, 0, 8);
    // BiTree T = CreateBiTreeInPost(inlist, 0, 8, postlist, 0, 8);

    printf("Preorder:\t"), PreOrderTraverse(T, PrintElement), putchar('\n');
    printf("Inorder:\t"), InOrderTraverse(T, PrintElement), putchar('\n');
    printf("Postorder:\t"), PostOrderTraverse(T, PrintElement), putchar('\n');

    puts("");
    printf("The number of nodes:\t%d\n", PostOrderCount(T));
    printf("Depth:\t%d\n", PostOrderDepth(T));

    puts("");
    InOrderChildren(T), putchar('\n');
    InOrderParent(T, NULL), putchar('\n');
    InOrderLevel(T, 1), putchar('\n');

    PreOrderDestroy(T);
    return 0;
}