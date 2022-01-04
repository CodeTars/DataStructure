#include "SqList.h"


//-----------------------升序表的合并------------------------
void MergeList_Sq(SqList La, SqList Lb,  SqList &Lc)
{
	int i, j, k;
	int La_len, Lb_len;
	ElemType ai, bj;

	i = j = 1;
	k = 0;
	La_len = ListLength_Sq(La);
	Lb_len = ListLength_Sq(Lb);

	while((i <= La_len) && (j <= Lb_len))
	{
		GetElem_Sq(La, i, ai);
		GetElem_Sq(Lb, j, bj);

		if (!greater(ai, bj))  //  ai < bj
		{
			ListInsert_Sq(Lc, ++k, ai);
			++i;
		}
		else
		{
			ListInsert_Sq(Lc, ++k, bj);
			++j;
		}
	}

	while (i <= La_len) 
	{
		GetElem_Sq(La, i++, ai);
		ListInsert_Sq(Lc, ++k, ai);
	}

	while (j <= Lb_len) 
	{
		GetElem_Sq(Lb, j++, bj);	
		ListInsert_Sq(Lc, ++k, bj);
	}
}

//----------------------两个集合的并集---------------------------
void Union_Sq(SqList &La, SqList Lb)
{
	int La_len, Lb_len;
	ElemType e;

	La_len = ListLength_Sq(La);
	Lb_len = ListLength_Sq(Lb);

	for (int i = 1; i <= Lb_len; i++)
	{
		GetElem_Sq(Lb, i, e);

		if(!LocateElem_Sq(La, e, equal))
			ListInsert_Sq(La, ++La_len, e);
	}
}

int main() {
	SqList La, Lb, Lc;

	InitList_Sq(La);
	InitList_Sq(Lb);
	InitList_Sq(Lc);

	// La = {1, 2, ..., 10}
	for (int i = 1; i <= 10; i++)
		ListInsert_Sq(La, i, i);

	// Lb={6, 7, ..., 15}
	for (int j = 1; j <= 10; j++)
		ListInsert_Sq(Lb, j, j+5);  

	printf("the elements of SqList A is:\n");
	ListTraverse_Sq(La, output);
	printf("\n");

	printf("the elements of SqList B is:\n");
	ListTraverse_Sq(Lb, output);
	printf("\n");

	MergeList_Sq(La, Lb, Lc); 
	printf("the elements of the merged asending SqList is:\n");
	ListTraverse_Sq(Lc, output);
	printf("\n");

	Union_Sq(La, Lb);
	printf("the elements of the union SqList is:\n");
	ListTraverse_Sq(La, output);
	printf("\n");

	DestroyList_Sq(La);
	DestroyList_Sq(Lb);
	DestroyList_Sq(Lc);

	return 0;
}