/*
 * E89 Pedagogical & Technical Lab
 * project:     Immersion
 * created on:  2022-09-29 - 13:12 +0200
 * 1st author:  martin.leroy - martin.leroy
 * description: répéter un caractère
 */

#include "printf.h"

void stu_repeat_char(char c, int n, int fd)
{
    int x;

    x = 0;
    while (x < n) {
        stu_putchar(fd ,c);
        x = x + 1;
    }
}

