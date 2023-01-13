/*
 * E89 Pedagogical & Technical Lab
 * project:     tr
 * created on:  2022-10-17 - 11:11 +0200
 * 1st author:  martin.leroy - martin.leroy
 * description: found same character ?
 */

int stu_strchr2(const char *s, char accept)
{
    int i;

    i = 0;
    while (s[i] != '\0') {
        if (s[i] == '\\' && s[i +1] == 'n') {
            return(0);
        }
        if (accept == s[i]) {
            return (1);
        }
        i = i + 1;
    }
    return (0);
}
