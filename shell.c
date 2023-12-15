#include "jcshell.h"

int main(void)
{
    char *command;

while (1)
{
    size_t len = 0; /* Move the declaration to the beginning */
    ssize_t read_len;

    custom_print("$ ");

    read_len = getline(&command, &len, stdin);


        if (read_len == -1)
        {
            custom_print("\n");
            free(command);
            break;  /* Exit on end-of-file (Ctrl+D) */
        }

        if (read_len > 0 && command[read_len - 1] == '\n')
            command[read_len - 1] = '\0';  /* Remove newline character */

        execute_command(command);

        free(command);
    }

    return 0;
}
