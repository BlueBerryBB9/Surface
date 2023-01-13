/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2023-01-12 - 08:54 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: bourrage
 */

#include "printf.h"

/*
 * int bourrage(int fd,int arg, int *n, const char *pattern)
 * {
 *     printf("arg : %d\n", arg);
 *     printf("fd : %d\n", fd);
 *     printf("n : %d\n", *n);
 *     printf("pattern : %s\n", pattern);
 *     return(0);
 * }
 */

/*
 * int digit_signe(int i)
 * {
 *     if (i > 0) {
 *         return (1);
 *     }
 *     return (0);
 * }
 */

int br_signe(int fd, int varg, int *n, const char *pattern, int *cptr)
{
    int signe;

    signe = 0;
    if (pattern[*n] == '+') {
        if (varg > 0) {
            signe = 1;
            *n = *n + 1;
            *cptr = *cptr + 1;
        } else {
            signe = 0;
            *n = *n + 1;
        }
    }
    return (signe);
}

int bourrage(int fd, int varg, int *n, const char *pattern)
{
    int cptr;
    char bour;
    int signe;
    int nbr;

    nbr = 0;
    bour = ' ';
    cptr = 0;
    signe = br_signe(fd, varg, n, pattern, &cptr);
    if (pattern[*n] == '0') {
        bour = '0';
    }
    while (pattern[*n] != 'd') {
        nbr = nbr + (pattern[*n] - '0');
        nbr = nbr * 10;
        cptr = cptr + 1;
    }
    nbr = nbr / 10;
    return(0);
}
