// env_shell.c
#include "jcshell.h"

void print_environment(void)
{
    extern char **environ;
    char **env = environ;

    while (*env)
    {
        custom_print(*env);
        custom_print("\n");
        env++;
    }
}
