#include "holberton.h"
/*
 * parse_line - Function that split and add the content of buffer
 * into a list of arguments.
 *
 * @buffer: Pointer type char
 *
 * Return: Pointer with the list of arguments or NULL if failed
 */
char **parse_line(char *buffer)
{
	char **tokens, *token;
	int len = 0;

	tokens = malloc(sizeof(tokens) * BUFFERSIZE);

	if (tokens == NULL)
		return(NULL);

	token = strtok(buffer, " ");

	while (token != NULL)
	{
		tokens[len] = token;
		token = strtok(NULL, " ");
		len++;
	}

	return (tokens);
}
