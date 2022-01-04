#include "ElemType_int.h"

Status equal(ElemType e1, ElemType e2) {
	return e1 == e2 ? TRUE : FALSE;
}

Status greater(ElemType e1, ElemType e2) {
	return e1 > e2 ? TRUE : FALSE;
}

void input(ElemType &e) {
	scanf("%d", &e);
}

void output(ElemType &e) {
	printf("%d ", e);
}