/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2023-01-12 - 08:54 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: bourrage
 */

#include "printf.h"

static int puts_space(int fd, int nbr, int varg, int *signe)
{
    int nblen;
    int n;

    nblen = stu_nb_len(varg);
    if (varg < 0) {
        nblen = nblen + 1;
    }
    if (nbr <= nblen) {
        n = stu_print_base10(fd, varg);
        return (n);
    }
    stu_repeat_char(' ', ((nbr - (int)*signe) - nblen), fd);
    if ((int)*signe == 1) {
        puts_plus(fd, "+", 0);
    }
    n = stu_print_base10(fd, varg);
    return (n);
}

static int puts_zero(int fd, int nbr, int varg, int *signe)
{
    int nblen;
    int n;

    if ((int)*signe == 1) {
        puts_plus(fd, "+", 0);
        nbr = nbr - 1;
    }
    nblen = stu_nb_len(varg);
    if (varg < 0) {
        puts_plus(fd, "-", 0);
        varg = varg * -1;
        nblen = nblen + 1;
    }
    if (nbr <= nblen) {
        n = stu_print_base10(fd, varg);
        return (n);
    }
    stu_repeat_char('0', (nbr - nblen), fd);
    n = stu_print_base10(fd, varg);
    return (n);
}

static int br_signe(int varg, int *n, const char *pattern)
{
    int signe;

    signe = 0;
    if (pattern[*n] == '+') {
        if (varg > 0) {
            signe = 1;
            *n = *n + 1;
        } else {
            signe = 0;
            *n = *n + 1;
        }
    }
    return (signe);
}

int bourrage(int fd, int varg, int *n, const char *pattern)
{
    char bour;
    int signe;
    int nbr;

    nbr = 0;
    bour = ' ';
    signe = br_signe(varg, n, pattern);
    if (pattern[*n] == '0') {
        bour = '0';
    } while (pattern[*n] == ' ') {
        *n = *n + 1;
    }
    while (pattern[*n] != 'd') {
        nbr = nbr + (pattern[*n] - '0');
        nbr = nbr * 10;
        *n = *n + 1;
    }
    nbr = nbr / 10;
    if (bour == '0'){
        puts_zero(fd, nbr, varg, &signe);
    } else {
        puts_space(fd, nbr, varg, &signe);
    }
    return(0);
}
