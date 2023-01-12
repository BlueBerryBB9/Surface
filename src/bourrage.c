/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2023-01-12 - 08:54 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: bourrage
 */

#include "printf.h"

int bourrage(int fd,int arg, int *n, const char *pattern)
{
    printf("arg : %d\n", arg);
    printf("fd : %d\n", fd);
    printf("n : %d\n", *n);
    printf("pattern : %s\n", pattern);
    return(0);
}
