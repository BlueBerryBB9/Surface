/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2023-01-09 - 11:20 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: printf function
 */

#include "printf.h"

const char *hexa = "0123456789abcdef";

static int hexa_pf(void *c)
{
    int i;
    int str;
    char *stck;

    i = 0;
    str = (int)c;
    stck = malloc(sizeof(char) * (nblen(str) + 1));
    while (nb >= 0) {
        if (str <= 16) {
            stck[i] = hexa[str];
        } else if (str > 16) {
            stck[i] = hexa[str % 16];
            str = str / 16;
            i = i + 1;
        }
    }
    rev(stck);
    puts_plus(1, stck, 0);
    return (i);
}

int pf_sort(va_list *la, char c)
{
    int n;

    n = 0;
    if (c == '%' || c == 'c') {
        if (c == '%') {
            n = stu_putchar('%');
        } else {
            n = stu_putchar(va_arg(*la, char));
        }
    } else if (c == 's' || c == 'p') {
        if (c == 's') {
            n = puts_plus(1, va_arg(*la, char *));
        } else {
            n = hexa_pf(va_arg(*la, void *));
        }
    } else {
        n = print_base10(va_arg(*la, int));
    }
    return (n);
}
