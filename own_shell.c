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
	int status_process = 0, is_there;
	char *full_path, *the_path;

	the_path = malloc((sizeof(char) * _strlen(args[0])) + 1);
	_strcpy(the_path, args[0]);
	full_path = strtok(the_path, "/");
	full_path = strtok(NULL, "/");

	is_there = stat(args[0], &stat_var);
	if ((full_path != NULL) && is_there == 0)
		status_process = 2;

	if (full_path == NULL)
	{
		status_process = process_path(args, env);
		if (status_process == -1)
		{
			free(the_path);
			free(input_buff);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	free(the_path);
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
	char *input_buff, **args, *str_error;
	int status = 0, status_process = 0;

	do {
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
		if (args != NULL)
		{
			if ((built_commands(args, input_buff, env)) == 0)
			{
				status_process = init_commands(args, input_buff
							       , env);
				if (status_process == 1 || status_process == 2)
					status = execution_line(args,
								input_buff,
								status_process);
				if (status_process == 0)
				{
					str_error = args[0];
					_strcat(str_error,
						": command not found\n");
					write(STDERR_FILENO, str_error,
					      _strlen(str_error));
					free(args);
					free(input_buff);
				}
			}
		}
		else
			status = 1;
	} while (status);
}
