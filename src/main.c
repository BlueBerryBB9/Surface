/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2023-01-10 - 16:42 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: main
 */

#include "printf.h"

int main(void)
{
    int n;

    n = stu_dprintf(1, "%d\n", 12);
    stu_dprintf(2, "bytes printed %d\n", n);
}
