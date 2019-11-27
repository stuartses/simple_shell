#include "holberton.h"
/**
 * execution_line - Function that execute a command line.
 *
 * @args: Pointer type char
 * @buffer: Pointer type char
 * @status_process: Variable type int
 *
 * Return: int
 */
int execution_line(char **args, char *buffer, int status_process)
{
	pid_t new_pid;

	new_pid = fork();
	if (new_pid == 0)
	{
		if ((execve(args[0], args, NULL)) == -1)
		{
			perror(args[0]);
			free(args);
			free(buffer);
			exit(0);
		}
	}
	else
	{
		wait(NULL);
	}

	if (status_process == 1)
	{
		free(args[0]);
	}

	free(args);
	free(buffer);
	return (1);
}
