#include <holberton.h>
/**
 * prompt - get from standard input
 *
 * Description: get string from standard input
 * Return: string
 */
char *prompt(void)
{
	char *buffer;
	size_t buffer_size = BUFFERSIZE, getline_out;
	int buff_len = 0;

	buffer = malloc(sizeof(char) * buffer_size);
	printf("$ ");
	getline_out = getline(&buffer, &buffer_size, stdin);

	while (buffer[buff_len] != '\n')
		buff_len++;
	buffer[buff_len] = '\0';

	return (buffer);
}
