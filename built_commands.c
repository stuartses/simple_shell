#include "holberton.h"
/**
 * enviroment - print the enviroment variables
 * @env: enviroment variables
 *
 * Description: print the enviroment variables in simple shell
 *
 * Return: void
 */
void enviroment(char **env)
{
	int env_i = 0;

	while (env[env_i] != NULL)
	{
		write(STDOUT_FILENO, env[env_i], _strlen(env[env_i]));
		write(STDOUT_FILENO, "\n", 1);
		env_i++;
	}
}

/**
 * built_commands - Function that compare and execute built-in commands
 *
 * @args: Pointer to pointer type char
 * @buffer: Pointer type char
 * @env: Pointer to pointer type char
 *
 * Return: int
 */
int built_commands(char **args, char *buffer, char **env)
{
	if ((_strcmp(args[0], "exit")) == 0)
	{
		free(buffer);
		free(args);
		exit(0);
		return (1);
	}
	else if ((_strcmp(args[0], "env")) == 0)
	{
		enviroment(env);
		free(buffer);
		free(args);
		return (1);
	}

	return (0);
}
/**
 * handle_sigint - take signal from stdin
 * @sig: signal value
 *
 * Description: take a signal from stdin and prints it
 * Return: void
 */
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
