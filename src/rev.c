/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2023-01-11 - 08:57 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: rev
 */

#include "printf.h"

char *rev(const char *c)
{
    int i;
    int r;
    char *res;

    i = 0;
    r = (stu_strlen(c) - 1);
    res = malloc(sizeof(char) * (stu_strlen(c) + 1));
    while (r >= 0) {
        res[r] = c[i];
        r = r - 1;
        i = i + 1;
    }
    res[i] = '\0';
    return (res);
}
