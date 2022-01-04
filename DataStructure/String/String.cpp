#include "String.h"

Status StrAssign(HString& T, char* chars)
{
    if (T.ch) {
        free(T.ch);
        T.ch = NULL;
    }
    if (T.length = strlen(chars)) {
        T.ch = (char*)malloc(sizeof(char) * T.length);
        if (T.ch == NULL)
            exit(OVERFLOW);
        for (int i = 0; i < T.length; i++) {
            T.ch[i] = chars[i];
        }
    }

    return OK;
}

Status StrCopy(HString& T, HString S)
{
    if (T.ch) {
        free(T.ch);
        T.ch = NULL;
    }
    if (T.length = S.length) {
        T.ch = (char*)malloc(sizeof(char) * T.length);
        if (T.ch == NULL)
            exit(OVERFLOW);
        for (int i = 0; i < T.length; i++) {
            T.ch[i] = S.ch[i];
        }
    }
    return 0;
}

Status ClearString(HString& S)
{
    if (S.ch) {
        free(S.ch);
        S.ch = NULL;
    }
    S.length = 0;
    return OK;
}

Status StrEmpty(HString S)
{
    return S.length == 0 ? 1 : 0;
}

int StrLength(HString S)
{
    return S.length;
}

/* 比较 */
int StrCompare(HString S, HString T)
{
    /* 如果S < T, 返回一个负数. S = T, 返回0. S > T, 返回一个正数. */
    for (int i = 0; i < S.length && i < T.length; i++) {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

/* 联接 */
Status Concat(HString& T, HString S1, HString S2)
{
    if (T.ch) {
        free(T.ch);
        T.ch = NULL;
    }
    if (T.length = S1.length + S2.length) { // 非零则执行
        T.ch = (char*)malloc(sizeof(char) * T.length);
        if (T.ch == NULL)
            exit(OVERFLOW);
        for (int i = 0; i < T.length; i++) {
            T.ch[i] = (i < S1.length ? S1.ch[i] : S2.ch[i - S1.length]);
        }
    }

    return OK;
}

/* 求子串 */
Status SubString(HString& Sub, HString S, int pos, int len)
{
    if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1) {
        return ERROR;
    }

    if (Sub.ch) {
        free(Sub.ch);
        Sub.ch = NULL;
    }
    if (Sub.length = len) { // 子串长度非0时执行
        Sub.ch = (char*)malloc(sizeof(char) * Sub.length);
        if (Sub.ch == NULL)
            exit(OVERFLOW);
        for (int i = 0; i < len; i++) {
            Sub.ch[i] = S.ch[pos - 1 + i];
        }
    }
    return OK;
}

/* 插入 */
Status StrInsert(HString& S, int pos, HString T)
{
    if (pos < 1 || pos > S.length + 1) {
        return ERROR;
    }

    if (T.length) { // 插入串非空时执行
        S.ch = (char*)realloc(S.ch, sizeof(char) * (S.length + T.length));
        if (S.ch == NULL)
            exit(OVERFLOW);
        for (int i = S.length - 1; i >= pos - 1; i--) {
            S.ch[i + T.length] = S.ch[i];
        }
        for (int i = 0; i < T.length; i++) {
            S.ch[pos - 1 + i] = T.ch[i];
        }
        S.length += T.length;
    }

    return OK;
}

/* 删除 */
Status StrDelete(HString& S, int pos, int len)
{
    if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1) {
        return ERROR;
    }
    S.length -= len;
    for (int i = pos - 1; i < S.length; i++) {
        S.ch[i] = S.ch[i + len];
    }
    S.ch = (char*)realloc(S.ch, sizeof(char) * S.length); // 省内存, 可删

    return OK;
}

void StrPrint(HString S)
{
    for (int i = 0; i < S.length; i++) {
        putchar(S.ch[i]);
    }
    putchar('\n');
}
