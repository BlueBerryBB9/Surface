#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef PRINTF_H

#define PRINTF_H

int stu_dprintf(int fd, const char *pattern, ...);
int pf_sort(int fd, va_list *la, char c, int *n, const char *pattern);
int puts_plus(int channel, const char *str, int rt);
unsigned int stu_strlen(const char *str);
int stu_print_base10(int fd, int nb);
char *rev(const char *c);
int bourrage(int fd, int arg, int *n, const char *pattern);
int stu_nb_len(int nb);
void stu_repeat_char(char c, int n, int fd);
int stu_putchar(int fd, char c);

#endif /* PRINTF_H */
