#include "shell.h"
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;
		
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&line, &len, stdin);
		
	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	
	
	
	return (line);
}

               /*array = tokenize_input(buf);

                child_process = create_child_process(array);

                waitpid(child_process, &menu, 0);
                free(array);

}
        free(buf);

        return (n);
}*/


