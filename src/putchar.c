#include <unistd.h>

int stu_putchar(int fd, char c)
{
    return (write (fd, &c, 1));
}
