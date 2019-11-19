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

	while (status)
	{
		printf("$ ");
		input_buff = prompt();
		args = parse_line(input_buff);
		status = execution_line(args);
		free(input_buff);
		free(args);
	}
}
