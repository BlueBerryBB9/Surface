/*
 * E89 Pedagogical & Technical Lab
 * project:     variadique
 * created on:  2023-01-09 - 10:02 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: mini printf
 */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int stu_print_base10(int nb);

int puts_plus(int channel, const char *str, int rt);

int stu_dprintf(const char *pattern, ...)
{
    va_list la;
    int n;

    n = 0;
    va_start(la, pattern);
    while (pattern[n] != '\0') {
        if (pattern[n] == '%' && pattern[n + 1] == 's') {
            puts_plus(1, va_arg(la, char *), 0);
            n = n + 1;
        } else if (pattern[n] == '%' && pattern[n + 1] == '%') {
            puts_plus(1, "%", 0);
            n = n + 1;
        } else if (pattern[n] == '%' && pattern[n + 1] == 'd'){
            stu_print_base10(va_arg(la, int));
            n = n + 1;
        } else if (pattern[n] == '\n') {
            write(1, "\n", 1);
        } else {
            write(1, &pattern[n], 1);
        }
        n = n + 1;
    }
    va_end(la);
    return (n);
}

int main(void)
{
    printf("taux: %d%% / valeur: %s / turlututu: %s\n",
           150, "hello world", "tata");
    return(stu_mini_printf("taux: %d%% / valeur: %s / turlututu: %s\n",
                           150, "hello world", "tata"));
}
