#include "holberton.h"
/**
 * prompt - get from standard input
 *
 * Description: get string from standard input
 * Return: string
 */
char *prompt(void)
{
	char *buffer;
	size_t buffer_size = BUFFERSIZE, getline_out = 0;
	int buff_len = 0;

	buffer = malloc(sizeof(char) * buffer_size);
	getline_out = getline(&buffer, &buffer_size, stdin);
	/*
	while (getline_out != '\n' && getline_out != EOF)
	{
		getline_out = getchar();
		buffer[buff_len] = getline_out;
		buff_len++;
	}
	*/

	if (getline_out == EOF)
	{
		write(STDERR_FILENO, "\n", 1);
		exit(0);
	}

	while (buffer[buff_len] != '\n')
		buff_len++;


       	buffer[buff_len] = '\0';

	return (buffer);
}
