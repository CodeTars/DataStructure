#include "PreDefined.h"
#include <string.h>

typedef struct
{
	// 增加安全性
    char* ch = NULL;
    int length = 0;
} HString;

Status StrAssign(HString &T, char *chars);
Status StrCopy(HString &T, HString S);
Status ClearString(HString &S);
Status StrEmpty(HString S);
int StrLength(HString S);
int StrCompare(HString S, HString T);
Status Concat(HString &T, HString S1, HString S2);
Status SubString(HString &Sub, HString S, int pos, int len);
Status StrInsert(HString &S, int pos, HString T);
Status StrDelete(HString &S, int pos, int len);
void StrPrint(HString s);
