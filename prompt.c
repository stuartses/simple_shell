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

	getline_out = getline(&buffer, &buffer_size, stdin);

	if (getline_out == EOF)
	{
		write(STDERR_FILENO, "\n", 1);
		exit(0);
	}

       	buffer[getline_out - 1] = '\0';
}
