#include <stdarg.h>
#include <unistd.h>

#ifndef PRINTF_H

#define PRINTF_H

int puts_plus(int channel, const char *str, int rt);
unsigned int stu_strlen(const char *str);
int stu_print_base10(int nb);

#endif /* PRINTF_H */
