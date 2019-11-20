#include "holberton.h"
/*
 * parse_line - Function that split and add the content of buffer
 * into a list of arguments.
 *
 * @buffer: Pointer type char
 *
 * Return: Pointer with the list of arguments or NULL if failed
 */
void parse_line(char *buffer, char **tokens)
{
	char *token;
	int len = 0;

	if (tokens == NULL)
	{
		write(STDERR_FILENO, "Error assign memory\n", 50);
		free(tokens);
		/* return(NULL); */
	}

	token = strtok(buffer, " ");
	while (token != NULL)
	{
		tokens[len] = token;
		token = strtok(NULL, " ");
		len++;
	}

	tokens[len] = NULL;

}
