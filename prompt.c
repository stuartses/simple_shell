#include "holberton.h"
/**
 * prompt - get from standard input
 *
 * Description: get string from standard input
 *
 * @buffer: Pointer type char
 *
 * Return: void
 */
void prompt(char *buffer)
{
	ssize_t getline_out = 1;
	size_t buffer_size = BUFFERSIZE;
	int i = 0, stat_buffer = 0, stat_issatty = isatty(STDIN_FILENO);

	while (getline_out == 1 && stat_buffer != 1)
	{
		if (stat_issatty)
			write(STDOUT_FILENO, "$ ", 2);
		getline_out = getline(&buffer, &buffer_size, stdin);

		while (buffer[i] != '\n')
		{
			if (buffer[i] != ' ')
			{
				stat_buffer = 1;
				break;
			}
			else
				stat_buffer = 0;
			i++;
		}
	}

	if (getline_out == EOF)
	{
		if (stat_issatty)
			write(STDOUT_FILENO, "\n", 1);
		free(buffer);
		exit(0);
	}

	buffer[getline_out - 1] = '\0';
}
