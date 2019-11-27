#include "holberton.h"
/**
 * parse_line - Function that split and add the content of buffer
 * into a list of arguments.
 *
 * @buffer: Pointer type char
 *
 * Return: Pointer with the list of arguments or NULL if failed
 */
char **parse_line(char *buffer)
{
	char *token, **tokens;
	int len = 0;

	tokens = malloc(sizeof(tokens) * BUFFERSIZE);

	if (tokens == NULL)
	{
		write(STDERR_FILENO, "Error assign memory\n", 50);
		free(buffer);
		free(tokens);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, STR_DELIM);

	while (token != NULL)
	{
		tokens[len] = token;
		token = strtok(NULL, " ");
		len++;
	}

	tokens[len] = NULL;

	return (tokens);
}
