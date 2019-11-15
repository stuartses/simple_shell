#include <stdlib.h>
#include <stdio.h>
int main (void)
{
	char *buffer;
	size_t buffer_size = 50;
	size_t getline_out;

	buffer = malloc(sizeof(char) * buffer_size);
	printf("$ ");
	getline_out = getline(&buffer, &buffer_size, stdin);
	printf("%s", buffer);
	free(buffer);

	return (0);
}
