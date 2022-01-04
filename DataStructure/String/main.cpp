#include "String.h"

int main()
{
    HString s, t, r;
    char str1[] = "Hello world!";
    char str2[] = "Hello world";
    char str3[] = "To be or not to be, this is a question!";

    StrAssign(s, str1);
    printf("调用StrAssign(s, str1)后, s: "), StrPrint(s);
    printf("StrLength(s) = %d\n\n", StrLength(s));

    StrCopy(t, s);
    printf("调用StrCopy(t, s)后, t: "), StrPrint(t);

    ClearString(t);
    printf("调用ClearString(t)后, ");
    printf("t是否空? %s\n\n", StrEmpty(t) ? "yes" : "no");

    StrAssign(t, str1);
    printf("调用StrAssign(t, str1)后, t: "), StrPrint(t);
    printf("调用StrCompare(s, t), 返回: %d\n\n", StrCompare(s, t));

    StrAssign(t, str2);
    printf("调用StrAssign(t, str2)后, t: "), StrPrint(t);
    printf("调用StrCompare(s, t), 返回: %d\n\n", StrCompare(s, t));

    StrAssign(t, str3);
    printf("调用StrAssign(t, str3)后, t: "), StrPrint(t);
    printf("调用StrCompare(s, t), 返回: %d\n\n", StrCompare(s, t));

    Concat(r, s, t);
    printf("调用Concat(r, s, t)后, r: "), StrPrint(r);
    putchar('\n');

    SubString(r, s, 7, 5);
    printf("调用SubString(r, s, 7, 5)后, r: "), StrPrint(r);
    putchar('\n');

    StrInsert(r, 6, t);
    printf("调用StrInsert(r, 6, t)后, r: "), StrPrint(r);
    putchar('\n');

    StrDelete(r, 6, 18);
    printf("调用StrDelete(r, 6, 18)后, r: "), StrPrint(r);
    putchar('\n');

    return 0;
}