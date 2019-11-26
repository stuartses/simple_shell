#include "holberton.h"
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
	int status = 1;
	struct stat stat_var;

	while (status)
	{
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
			if (stat(args[0], &stat_var) == -1)
			{
				if (process_path(args, env) == -1)
				{
					free(input_buff);
					free(args);
					exit(EXIT_FAILURE);
				}
			}

			status = execution_line(args, input_buff);
		}

		if (!isatty(STDIN_FILENO))
			exit(0);

	}
}
