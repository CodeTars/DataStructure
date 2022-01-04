#include "LinkList.h"

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pc = Lc = La;

	while (pa && pb) {
		if (pa->data < pb->data) {
			pc->next = pa;
			pa = pa->next;
		} else {
			pc->next = pb;
			pb = pb->next;
		}
		pc = pc->next;
	}

	pc->next = pa ? pa : pb;
	free(Lb);
}

int main() {
	LinkList La, Lb, Lc;

	InitList_L(La);
	InitList_L(Lb);
	InitList_L(Lc);
	
	// La = {1, 2, ..., 10}
	for (int i = 1; i <= 10; i++) ListInsert_L(La, i, i);
	// Lb={6, 7, ..., 15}
	for (int j = 1; j <= 10; j++) ListInsert_L(Lb, j, j+5);  

	// printf("%d\n", ListLength_L(La));

	printf("The elements of List A is:\n");
	ListTraverse_L(La, output); printf("\n");

	printf("The elements of List B is:\n");
	ListTraverse_L(Lb, output); printf("\n");

	MergeList_L(La, Lb, Lc); 
	printf("The elements of the merged asending List is:\n");
	ListTraverse_L(Lc, output); printf("\n");

	DestroyList_L(Lc);

	return 0;
}