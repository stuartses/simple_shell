#include "holberton.h"
/*
 * execution_line - Function that execute a command line.
 *
 * @args: Pointer type char
 * @buffer: Pointer type char
 *
 * Return: 1
 */
int execution_line(char **args, char *buffer, char *new_path)
{
	int compare;
	pid_t new_pid;

	new_pid = fork();

	compare = _strcmp(args[0], "exit");
	if (compare == 0)
	{
                free(buffer);
		free(args);
		free(new_path);
                exit(0);
	}

	if (new_pid == 0)
	{
		if ((execve(args[0], args, NULL)) == -1)
		{
			perror(args[0]);
			free(args);
			free(buffer);
			free(new_path);
			exit(0);
		}
	}
	else
	{
		wait(NULL);
	}

	free(args);
	free(buffer);
	free(new_path);
	return(1);
}
