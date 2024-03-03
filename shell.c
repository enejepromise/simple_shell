#include "shell.h"

/**
 * main - simple shell main function
 * ac: argument count
 * av: argument of values
 * Return - 0 Always sucess
 */
int main(int ac, char **argv, char **env)
{
	char *line = NULL; **char command = NULL;
	int i,  status = 0;
	(void) ac;

	while (1)
	{
		line  = read_line();
		if (line == NULL) /* when it reaches EOF or ctrl + D*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		
		command = tokenizer(line);
		if (!command)
			continue;

		for (i = 0; command[i]; i++)
		{
			printf("%s\n", command[i]);
			free(command[i]), command[i] = NULL;
		}
		free(command), command = NULL;

		
		status = _execute(command, argv);
	}
}

