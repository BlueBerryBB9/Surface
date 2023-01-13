/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2023-01-10 - 16:42 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: main
 */

#include "printf.h"
#include <string.h>
#include <stddef.h>

int main(void)
{
    int n;
    char *str;

    n = stu_dprintf(1, "%d\n", 12);
    stu_dprintf(2, "bytes printed %d\n", n);
    stu_dprintf(1, "%+04d\n", 56);
    str = NULL;
    stu_dprintf(1, "addr is %p\n", str);
    str = strdup("LUIGI");
    /*
     * dprintf(1, "luigiaddr : %p\n", str);
     */
    stu_dprintf(1, "addr is %p and str %s\n", str, str);
}
