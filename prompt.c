#include "holberton.h"
/**
 * prompt - get from standard input
 *
 * Description: get string from standard input
 * Return: string
 */
void prompt(char *buffer)
{
	ssize_t getline_out = 0;
	size_t buffer_size = BUFFERSIZE;
	int buff_len = 0;

	getline_out = getline(&buffer, &buffer_size, stdin);

	if (getline_out == EOF)
	{
		write(STDERR_FILENO, "\n", 1);
		exit(0);
	}

	while (buffer[buff_len] != '\n')
		buff_len++;

       	buffer[buff_len] = '\0';
}
