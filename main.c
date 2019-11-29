#include "holberton.h"
/**
 * main - call to Simple Shell
 *
 * Description: call the function to begins simple shell program
 *
 * @ac: Variable type int
 * @av: Pointer to pointer type char
 * @env: Pointer to pointer type char
 *
 * Return: int
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	signal(SIGINT, handle_sigint);
	own_shell(env);

	return (0);
}
