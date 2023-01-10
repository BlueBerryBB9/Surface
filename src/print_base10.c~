/*
 * E89 Pedagogical & Technical Lab
 * project:     variadique
 * created on:  2023-01-09 - 10:13 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: print base 10
 */

#include <unistd.h>

static void stu_putchar(char c)
{
    write (1, &c, 1);
}

static int stu_nb_len(int nb)
{
    int i;

    i = 0;
    while (nb != 0) {
        nb = nb / 10;
        i = i + 1;
    }
    return (i);
}

static int stu_get_digit(int nb, int index)
{
    int i;

    i = 0;
    while (i != index) {
        nb = nb / 10;
        i = i + 1;
    }
    return (nb % 10);
}

int stu_print_base10(int nb)
{
    int i;
    int j;
    int x;

    i = stu_nb_len(nb);
    i = i - 1;
    x = stu_nb_len(nb);
    if (nb > 2147483647 || nb < -2147483647) {
        return (-1);
    }
    if (nb < 0) {
        nb = nb * -1;
        stu_putchar('-');
        x = x + 1;
    } else if ( nb == 0) {
        write(1, "0\n", 2);
        return(1);
    }
    while (i >= 0) {
        j = stu_get_digit(nb, i);
        stu_putchar('0' + j);
        i = i - 1;
    }
    return (x);
}
