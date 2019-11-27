#include "holberton.h"
/**
 * init_commands - call process_path
 * @args: input arguments
 * @input_buff: buffer
 * @env: inviroments variables
 *
 * Description: take arguments and call process_path to complement
 * Return: void
 */
int init_commands(char **args, char *input_buff, char **env)
{
	struct stat stat_var;
	int status_process = 0;

	if (stat(args[0], &stat_var) == -1)
	{
		status_process = process_path(args, env);

		if (status_process == -1)
		{
			free(input_buff);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	return (status_process);
}

/**
 * own_shell - Simple Shell
 *
 * @env: enviroment variables
 *
 * Description: Own Simple Shell
 *
 * Return: void
 */
void own_shell(char **env)
{
	char *input_buff, **args;
	int status = 1, status_process = 0;

	while (status)
	{
		status_process = 0;

		input_buff = malloc(sizeof(input_buff) * BUFFERSIZE);

		if (input_buff == NULL)
		{
			write(STDERR_FILENO, "Error assign memory\n", 50);
			free(input_buff);
			exit(EXIT_FAILURE);
		}

		prompt(input_buff);
		args = parse_line(input_buff);

		if ((built_commands(args, input_buff, env)) == 0)
		{
			status_process = init_commands(args, input_buff, env);
			status = execution_line(args, input_buff,
						status_process);
		}

		if (!isatty(STDIN_FILENO))
			exit(0);
	}
}
