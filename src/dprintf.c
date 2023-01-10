/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2023-01-09 - 11:20 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: printf function
 */

#include "printf.h"

int stu_dprintf(int fd, const char *pattern, ...)
{
    va_list la;
    int n;

    n = 0;
    va_start(la, pattern);
    while (pattern[n] != '\0') {
        if (pattern[n] == '%') {
            n = n + 1;
            pf_sort(fd, &la, pattern[n]);
        } else {
            stu_putchar(fd, pattern[n]);
            n = n + 1;
        }
    }
    va_end(la);
    return (n);
}
