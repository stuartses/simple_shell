#include "holberton.h"
/**
 * enviroment - print the enviroment variables
 *
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
 * init_commands - call process_path
 * @args: input arguments
 * @input_buff: buffer
 * @env: inviroments variables
 *
 * Description: take arguments and call process_path to complement
 * Return: void
 */
void init_commands(char **args, char *input_buff, char **env)
{
	int status_process = 0;
	struct stat stat_var;

	if (stat(args[0], &stat_var) == -1)
	{
		status_process = process_path(args, env);
		if (status_process == -1)
		{
			free(input_buff);
			free(args);
			exit(EXIT_FAILURE);
		}
		/*
		 * else if (status_process == 0)
		 * {
		 *      write(STDOUT_FILENO,
		 *            "command not fount\n",25);
		 * }
		 */
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
