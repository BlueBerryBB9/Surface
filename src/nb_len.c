/*
 * E89 Pedagogical & Technical Lab
 * project:     Immersion
 * created on:  2022-09-29 - 16:26 +0200
 * 1st author:  martin.leroy - martin.leroy
 * description: quantité de chiffres dans un nombre
 */

int stu_nb_len(int nb)
{
    int x;

    x = 0;
    while (nb != 0) {
        nb = nb / 10;
        x = x + 1;
    }
    return (x);
}
