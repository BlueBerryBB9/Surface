/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2023-01-09 - 11:20 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: printf function
 */

#include "printf.h"

const char *hexa = "0123456789abcdef";

static int hexa_pf(int fd, void *c)
{
    int i;
    int addr;
    char *stck;

    i = 0;
    if (c == NULL) {
        i = i + puts_plus(1, "(null)", 0);
        return (i);
    }
    puts_plus(1, "0x", 0);
    addr = (int)c;
    stck = malloc(sizeof(char) * (stu_nb_len(addr) + 1));
    if (addr < 16) {
        stck[i] = hexa[addr];
    } else {
        while (addr > 0) {
            stck[i] = hexa[addr % 16];
            addr = addr / 16;
            i = i + 1;
        }
    }
    stck[i] = '\0';
    puts_plus(fd, rev(stck), 0);
    return (i);
}

int pf_sort(int fd, va_list *la, char c, int *n, const char *pattern)
{
    int i;

    i = 0;
    if (c == '%' || c == 'c') {
        if (c == 'c') {
            i = stu_putchar(fd, va_arg(*la, int));
        } else {
            i = write(fd, "%", 1);
        }
    } else if (c == 's' || c == 'p') {
        if (c == 's') {
            i = puts_plus(fd, va_arg(*la, char *), 0);
        } else {
            i = hexa_pf(fd, va_arg(*la, void *));
        }
    } else if (c == 'd') {
        i = stu_print_base10(fd, va_arg(*la, int));
    } else if (c == '+' || c == ' ' || (c >= '0' && c <= '9')){
        i = bourrage(fd, va_arg(*la, int), n, pattern);
    }
    return (i);
}
