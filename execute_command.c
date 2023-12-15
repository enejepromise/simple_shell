#include "jcshell.h"

void execute_command(const char *command)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) /* Child process */
    {
        char *args[2];
        args[0] = (char *)command;
        args[1] = NULL;

        if (execve(args[0], args, NULL) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else /* Parent process */
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
