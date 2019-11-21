#include "holberton.h"
/**
 * main - call to Simple Shell
 *
 * Description: call the function to begins simple shell program
 * Return: void
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	own_shell(env);

	return (0);
}
