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
	int sh_exec;

	printf("$ ");
	input_buff = prompt();
	/* args = return from Parse Function (argument: input_buff) */
	/* sh_exec = return from execution function (argument: args) */
	free(input_buff);
	free(args);
}
