#include "shell.h"

/**
 * main - wait program
 * argc: argument count
 * argv: arrays  of values
 * env: enviroment variable
 * Return - 0 Always sucess
 */
int main(int argc, char *argv[], char **env)
{
	char *lineptr;
	(void)argc;

	while (1)
	{
		print_prompt();
		lineptr = read_input();
		execute_command(lineptr, argv, env);
		free(lineptr);
	}

	return (0);
}

