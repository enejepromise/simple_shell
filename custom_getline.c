// custom_getline.c
#include "jcshell.h"

char *custom_getline(void)
{
    static char buffer[BUFFER_SIZE];
    static size_t buffer_index = 0;
    static size_t line_index = 0;

    char *line = NULL;
    size_t line_size = 0;

    while (1)
    {
        if (buffer_index == 0)
        {
            ssize_t bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            
            if (bytesRead <= 0)
                break;
            
            line_index = 0;
        }

        if (buffer[buffer_index] == '\n' || buffer[buffer_index] == '\0')
        {
            buffer[buffer_index] = '\0';
            line = realloc(line, line_size + buffer_index - line_index + 1);

            if (!line)
            {
                custom_print("Memory allocation error\n");
                exit(EXIT_FAILURE);
            }

            strcpy(line + line_size, buffer + line_index);
            line_size += buffer_index - line_index + 1;
            line_index = buffer_index + 1;
            break;
        }

        buffer_index++;

        if (buffer_index == BUFFER_SIZE)
        {
            buffer_index = 0;
            line = realloc(line, line_size + BUFFER_SIZE);
            
            if (!line)
            {
                custom_print("Memory allocation error\n");
                exit(EXIT_FAILURE);
            }

            strcpy(line + line_size, buffer);
            line_size += BUFFER_SIZE;
        }
    }

    return line;
}
