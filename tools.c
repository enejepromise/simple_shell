#include "shell.h"
void freearrayof2D(char **arr)
{
	int i;
	if (!arr)
		return;
	
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr), arr = NULL;
}

