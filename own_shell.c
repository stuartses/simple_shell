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
	int sh_exec, status = 1;
	size_t buffer_size = BUFFERSIZE;

	while (status)
	{
		input_buff = malloc(sizeof(char*) * buffer_size);

		write(STDERR_FILENO, "$ ", 2);
		prompt(input_buff);
		args = parse_line(input_buff);
		status = execution_line(args);
		free(input_buff);
		free(args);
	}
}
