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
	int sh_exec, i = 0;

	printf("$ ");
	input_buff = prompt();
	args = parse_line(input_buff);

	while (args[i] != '\0')
	{
		printf("[%i] %s\n", i, args[i]);
		i++;
	}

	/* sh_exec = return from execution function (argument: args) */
	free(input_buff);
	free(args);
}
