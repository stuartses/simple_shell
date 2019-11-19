#include "holberton.h"
/*
 * execution_line - Function that execute a command line.
 *
 * @arg: Pointer type char
 *
 * Return: 1
 */
int execution_line(char **args)
{
	pid_t new_pid;

	new_pid = fork();

	/*if (args[0] == "exit")
	  return(0);*/

	if (new_pid == 0)
	{
		if ((execve(args[0], args, NULL)) == -1)
		{
			perror(args[0]);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}

	return (1);
}
