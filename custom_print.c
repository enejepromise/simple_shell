#include "jcshell.h"
#include <unistd.h>

void custom_print(const char *str)
{
    while (*str)
    {
        write(STDOUT_FILENO, str, 1);
        str++;
    }
}
