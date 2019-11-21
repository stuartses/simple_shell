#include "holberton.h"
/**
 * own_shell - Simple Shell
 *
 * Description: Own Simple Shell
 * Return: void
 */
void own_shell(void)
{
	char *input_buff;
	char **args;
	int status = 1;

/*
	if (isatty(STDIN_FILENO) == 0)
	{
		prompt(input_buff);
		execution_line(parse_line(input_buff, args));
		exit(0);
	}
*/

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
		status = execution_line(args, input_buff);
	}
}
